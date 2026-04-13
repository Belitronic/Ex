/*
  ESP32-C6 + 1.47" TFT 172x320 (Electrokit 41024695 / Waveshare Touch-LCD-1.47, 8MB)
  - AP Captive Portal: mata in SSID/PASS
  - STA Device page: IP + mDNS + Firmware-sida
  - Firmware-sida: listar assets i senaste GitHub Release (owner/repo)
  - Välj .bin -> ladda ner via HTTPS -> OTA flash -> reboot
  - Factory reset: rensar WiFi och startar om i AP-läge
  - OTA körs i separat FreeRTOS-task

  Bibliotek:
   - LovyanGFX
   - ArduinoJson (6.x)

  OBS (OTA):
   - Välj en Partition Scheme med OTA: Tools -> Partition Scheme -> (någon med OTA)
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <Preferences.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <Update.h>
#include <ArduinoJson.h>

#define LGFX_USE_V1
#include <LovyanGFX.hpp>

// ============================================================================
//  GitHub OTA: TYPER
// ============================================================================
struct AssetInfo {
  String name;
  String url;      // browser_download_url
  uint32_t size = 0;
  uint32_t dl_count = 0;
};

// ============================================================================
//  Display (LovyanGFX runtime-config) - Electrokit 41024695 pinout
//
//  SPI: SCLK=GPIO1, MOSI=GPIO2, MISO=GPIO3
//  LCD: CS=GPIO14, DC=GPIO15, RST=GPIO22, BL=GPIO23
//
//  NOTE: 172x320-paneler kan behöva offset_x=34. Se kommentar längre ned.
// ============================================================================
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_SPI      _bus;
  lgfx::Light_PWM    _light;

public:
  LGFX() {
    { // SPI bus
      auto cfg = _bus.config();

      cfg.spi_host   = SPI2_HOST;
      cfg.spi_mode   = 0;
      cfg.freq_write = 40000000;
      cfg.freq_read  = 16000000;

      cfg.spi_3wire  = false;      // vi har separat DC-pin
      cfg.use_lock   = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;

      cfg.pin_sclk = 1;   // SCLK
      cfg.pin_mosi = 2;   // MOSI
      cfg.pin_miso = 3;   // MISO
      cfg.pin_dc   = 15;  // DC

      _bus.config(cfg);
      _panel.setBus(&_bus);
    }

    { // Panel
      auto cfg = _panel.config();

      cfg.pin_cs   = 14;  // CS
      cfg.pin_rst  = 22;  // RST
      cfg.pin_busy = -1;

      cfg.panel_width  = 172;
      cfg.panel_height = 320;

      // Om bilden hamnar förskjuten i sidled på 172x320-paneler:
      //  - prova cfg.offset_x = 34;
      cfg.offset_x = 0;
      cfg.offset_y = 0;

      // Om färger blir knäppa:
      //  - prova cfg.invert = false;
      //  - prova cfg.rgb_order = true;
      cfg.invert     = true;
      cfg.rgb_order  = false;
      cfg.dlen_16bit = false;

      cfg.bus_shared = true; // bra om du delar SPI med SD senare

      _panel.config(cfg);
    }

    { // Backlight PWM
      auto cfg = _light.config();
      cfg.pin_bl = 23;       // BL
      cfg.invert = false;
      cfg.freq   = 5000;
      cfg.pwm_channel = 0;

      _light.config(cfg);
      _panel.setLight(&_light);
    }

    setPanel(&_panel);
  }
};

LGFX tft;

static void screen2(const String& l1, const String& l2 = "") {
  tft.fillScreen(0x0000);
  tft.setTextColor(0xE0E0, 0x0000);
  tft.setTextSize(2);
  tft.setCursor(8, 12);
  tft.println(l1);
  tft.setCursor(8, 52);
  tft.println(l2);
}

// ---------------- WiFi + Web ----------------
Preferences prefs;
WebServer server(80);
DNSServer dns;

static const char* NVS_NS_WIFI = "wifi";
static const char* KEY_SSID    = "ssid";
static const char* KEY_PASS    = "pass";

static const char* NVS_NS_OTA  = "ota";
static const char* KEY_OWNER  = "owner";
static const char* KEY_REPO   = "repo";

String apSsid;
String staSsid, staPass;

enum ModeState { MODE_AP_PORTAL, MODE_STA_DEVICE };
ModeState modeState = MODE_AP_PORTAL;

const IPAddress AP_IP(192, 168, 4, 1);
const IPAddress AP_GW(192, 168, 4, 1);
const IPAddress AP_MASK(255, 255, 255, 0);

uint32_t apShutdownAtMs = 0;

// Default GitHub target (kan ändras i web UI och sparas i NVS)
String ghOwner = "Belitronic";
String ghRepo  = "Ex";

// ============================================================================
//  OTA task state
// ============================================================================
static TaskHandle_t gOtaTaskHandle = nullptr;
static volatile bool gOtaInProgress = false;

// ---------------- Helpers ----------------
static String chipSuffix() {
  uint64_t mac = ESP.getEfuseMac();
  uint32_t low = (uint32_t)(mac & 0xFFFFFFFF);
  char buf[9];
  snprintf(buf, sizeof(buf), "%08lX", (unsigned long)low);
  return String(buf).substring(4);
}

static String htmlWrap(const String& title, const String& body) {
  String s;
  s += "<!doctype html><html><head><meta charset='utf-8'>";
  s += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  s += "<title>" + title + "</title>";
  s += "<style>"
       "body{font-family:system-ui,Arial;margin:20px;max-width:900px}"
       "input,button,select{font-size:16px;padding:10px;margin:6px 0;width:100%;box-sizing:border-box}"
       "button{cursor:pointer}"
       ".card{padding:16px;border:1px solid #ddd;border-radius:12px;margin:10px 0}"
       ".muted{color:#666} .ok{color:#0a7} .err{color:#c00}"
       "table{width:100%;border-collapse:collapse}"
       "td,th{border-bottom:1px solid #eee;padding:8px;text-align:left}"
       "</style>";
  s += "</head><body>";
  s += body;
  s += "</body></html>";
  return s;
}

static void saveCreds(const String& ssid, const String& pass) {
  prefs.begin(NVS_NS_WIFI, false);
  prefs.putString(KEY_SSID, ssid);
  prefs.putString(KEY_PASS, pass);
  prefs.end();
}

static bool loadCreds(String& ssid, String& pass) {
  prefs.begin(NVS_NS_WIFI, true);
  ssid = prefs.getString(KEY_SSID, "");
  pass = prefs.getString(KEY_PASS, "");
  prefs.end();
  return ssid.length() > 0;
}

static void clearCreds() {
  prefs.begin(NVS_NS_WIFI, false);
  prefs.remove(KEY_SSID);
  prefs.remove(KEY_PASS);
  prefs.end();
}

static void loadGithubTarget() {
  prefs.begin(NVS_NS_OTA, true);
  String o = prefs.getString(KEY_OWNER, "");
  String r = prefs.getString(KEY_REPO, "");
  prefs.end();
  if (o.length()) ghOwner = o;
  if (r.length()) ghRepo  = r;
}

static void saveGithubTarget(const String& owner, const String& repo) {
  prefs.begin(NVS_NS_OTA, false);
  prefs.putString(KEY_OWNER, owner);
  prefs.putString(KEY_REPO, repo);
  prefs.end();
  ghOwner = owner;
  ghRepo  = repo;
}

static bool connectSTA_only(const String& ssid, const String& pass, uint32_t timeoutMs = 15000) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), pass.c_str());
  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - start) < timeoutMs) delay(200);
  return WiFi.status() == WL_CONNECTED;
}

static bool connectSTA_APSTA(const String& ssid, const String& pass, uint32_t timeoutMs = 20000) {
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid.c_str(), pass.c_str());
  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - start) < timeoutMs) delay(200);
  return WiFi.status() == WL_CONNECTED;
}

// ============================================================================
//  GitHub: Hämta assets från latest release
// ============================================================================
static bool githubFetchLatestAssets(
  AssetInfo* out,
  size_t outMax,
  size_t& outCount,
  String& releaseTag,
  String& err
) {
  outCount = 0;
  err = "";
  releaseTag = "";

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient https;
  String apiUrl = "https://api.github.com/repos/" + ghOwner + "/" + ghRepo + "/releases/latest";

  if (!https.begin(client, apiUrl)) {
    err = "HTTPS begin fail";
    return false;
  }

  https.addHeader("User-Agent", "ESP32C6-OTA");
  https.addHeader("Accept", "application/vnd.github+json");

  int code = https.GET();
  if (code != 200) {
    err = "GitHub API HTTP " + String(code);
    https.end();
    return false;
  }

  DynamicJsonDocument doc(24 * 1024);
  DeserializationError jerr = deserializeJson(doc, https.getStream());
  https.end();

  if (jerr) {
    err = String("JSON error: ") + jerr.c_str();
    return false;
  }

  releaseTag = (const char*)(doc["tag_name"] | "");

  JsonArray assets = doc["assets"].as<JsonArray>();
  for (JsonObject a : assets) {
    if (outCount >= outMax) break;

    AssetInfo ai;
    ai.name = (const char*)(a["name"] | "");
    ai.url  = (const char*)(a["browser_download_url"] | "");
    ai.size = (uint32_t)(a["size"] | 0);
    ai.dl_count = (uint32_t)(a["download_count"] | 0);

    out[outCount++] = ai;
  }

  if (outCount == 0) {
    err = "No assets in latest release";
    return false;
  }

  return true;
}

// ============================================================================
//  OTA: Ladda ner och flasha vald .bin
// ============================================================================
static bool otaFlashFromUrl(const String& startUrl, String& err) {
  err = "";

  if (WiFi.status() != WL_CONNECTED) {
    err = "WiFi not connected";
    return false;
  }

  String url = startUrl;
  screen2("OTA:", "Startar...");

  const int MAX_REDIRECTS = 5;

  for (int attempt = 0; attempt < MAX_REDIRECTS; attempt++) {
    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient https;
    if (!https.begin(client, url)) {
      err = "HTTPS begin fail";
      return false;
    }

    https.addHeader("User-Agent", "ESP32C6-OTA");
    https.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);

    int code = https.GET();

    if (code == 200) {
      int totalLen = https.getSize();
      WiFiClient* stream = &https.getStream();

      if (!Update.begin(totalLen > 0 ? (size_t)totalLen : UPDATE_SIZE_UNKNOWN)) {
        err = "Update.begin failed (OTA partition?)";
        https.end();
        return false;
      }

      const size_t bufSize = 4096;
      uint8_t buf[bufSize];

      uint32_t writtenTotal = 0;
      uint32_t lastUi = 0;

      screen2("OTA:", "Laddar ner...");

      while (https.connected()) {
        size_t avail = stream->available();
        if (avail) {
          int r = stream->readBytes(buf, (avail > bufSize) ? bufSize : avail);
          if (r <= 0) break;

          size_t w = Update.write(buf, (size_t)r);
          delay(0);

          if (w != (size_t)r) {
            err = "Update.write mismatch";
            Update.abort();
            https.end();
            return false;
          }
          writtenTotal += (uint32_t)w;

          uint32_t now = millis();
          if (now - lastUi > 300) {
            lastUi = now;
            if (totalLen > 0) {
              int pct = (int)((writtenTotal * 100ULL) / (uint32_t)totalLen);
              screen2("OTA:", "Ner: " + String(pct) + "%");
            } else {
              screen2("OTA:", "Ner: " + String(writtenTotal / 1024) + " KB");
            }
          }
        } else {
          delay(1);
        }
      }

      if (!Update.end(true)) {
        err = String("Update.end fail: ") + Update.errorString();
        https.end();
        return false;
      }

      https.end();
      screen2("OTA:", "Klar! Reboot");
      delay(700);
      ESP.restart();
      return true;
    }

    if (code == 301 || code == 302 || code == 307 || code == 308) {
      String loc = https.header("Location");
      https.end();
      if (loc.length() == 0) {
        err = "Redirect utan Location";
        return false;
      }
      url = loc;
      screen2("OTA:", "Redirect...");
      continue;
    }

    err = "BIN HTTP " + String(code);
    https.end();
    return false;
  }

  err = "For manga redirects";
  return false;
}

// ============================================================================
//  OTA Task
// ============================================================================
static void otaTask(void* pv) {
  String* pUrl = (String*)pv;
  String url = *pUrl;
  delete pUrl;

  gOtaInProgress = true;
  screen2("OTA:", "Startar...");

  String err;
  bool ok = otaFlashFromUrl(url, err);

  if (!ok) {
    Serial.println("OTA failed: " + err);
    screen2("OTA fel", err);
  }

  gOtaInProgress = false;
  gOtaTaskHandle = nullptr;
  vTaskDelete(nullptr);
}

// ============================================================================
//  Captive Portal (AP)
// ============================================================================
static void startCaptivePortal() {
  modeState = MODE_AP_PORTAL;

  WiFi.mode(WIFI_AP);
  WiFi.disconnect(true, true);
  delay(200);

  apSsid = "ESP32C6-SETUP-" + chipSuffix();

  WiFi.softAPConfig(AP_IP, AP_GW, AP_MASK);
  WiFi.softAP(apSsid.c_str());

  dns.start(53, "*", AP_IP);

  screen2("AP-lage aktivt", apSsid + "\n192.168.4.1");

  server.on("/", HTTP_GET, []() {
    String body;
    body += "<h2>WiFi-installation</h2>";
    body += "<div class='card'>";
    body += "<p class='muted'>Anslut till <b>" + apSsid + "</b> och fyll i WiFi.</p>";
    body += "<form method='POST' action='/save'>";
    body += "<label>SSID</label><input name='ssid' required>";
    body += "<label>Lösenord</label><input name='pass' type='password'>";
    body += "<button type='submit'>Spara &amp; anslut</button>";
    body += "</form>";
    body += "<p class='muted'>Om sidan inte öppnas: <b>http://192.168.4.1/</b></p>";
    body += "</div>";
    server.send(200, "text/html", htmlWrap("WiFi Setup", body));
  });

  server.on("/save", HTTP_POST, []() {
    String ssid = server.arg("ssid"); ssid.trim();
    String pass = server.arg("pass");

    if (ssid.isEmpty()) { server.send(400, "text/plain", "SSID saknas"); return; }
    saveCreds(ssid, pass);

    String body;
    body += "<h2>Försöker ansluta...</h2><div class='card'>";
    body += "<p class='muted'>Ansluter till <b>" + ssid + "</b>...</p>";
    body += "</div><script>setTimeout(()=>location.href='/check',700);</script>";
    server.send(200, "text/html", htmlWrap("Connecting", body));
  });

  server.on("/check", HTTP_GET, []() {
    String ssid, pass;
    if (!loadCreds(ssid, pass)) {
      server.sendHeader("Location", "/");
      server.send(302, "text/plain", "");
      return;
    }

    screen2("Ansluter till:", ssid);

    bool ok = connectSTA_APSTA(ssid, pass, 15000);
    if (!ok) {
      screen2("WiFi misslyckades", "Prova igen");
      String body;
      body += "<h2 class='err'>Kunde inte ansluta</h2><div class='card'>";
      body += "<form method='POST' action='/wipe'><button type='submit'>Rensa &amp; börja om</button></form>";
      body += "<p><a href='/'>Tillbaka</a></p></div>";
      server.send(200, "text/html", htmlWrap("Failed", body));
      return;
    }

    IPAddress ip = WiFi.localIP();
    MDNS.end();
    MDNS.begin("esp32c6");

    screen2("WiFi ansluten!", ip.toString());
    modeState = MODE_STA_DEVICE;

    apShutdownAtMs = millis() + 10000;

    String body;
    body += "<h2 class='ok'>Ansluten!</h2><div class='card'>";
    body += "<p>Ny IP: <b>" + ip.toString() + "</b></p>";
    body += "<p><a href='http://" + ip.toString() + "/'>Öppna enhetssidan</a></p>";
    body += "<p class='muted'>Eller prova: <b>http://esp32c6.local/</b></p>";
    body += "<p class='muted'>Byt mobilen till ditt vanliga WiFi. AP stängs om ~10 sek.</p>";
    body += "</div>";
    server.send(200, "text/html", htmlWrap("Connected", body));
  });

  server.on("/wipe", HTTP_POST, []() {
    clearCreds();
    server.send(200, "text/html", htmlWrap("Wiped",
      "<h2>Rensat</h2><div class='card'><p>Startar om...</p></div>"));
    delay(300);
    ESP.restart();
  });

  server.onNotFound([]() {
    server.sendHeader("Location", String("http://") + AP_IP.toString() + "/");
    server.send(302, "text/plain", "");
  });

  server.begin();
}

// ============================================================================
//  Device routes (STA)
// ============================================================================
static void startDeviceRoutes() {
  server.on("/", HTTP_GET, []() {
    IPAddress ip = WiFi.localIP();
    String body;
    body += "<h2>Enhetssida</h2>";
    body += "<div class='card'>";
    body += "<p class='muted'>IP: <b>" + ip.toString() + "</b></p>";
    body += "<p class='muted'>mDNS: <b>http://esp32c6.local/</b></p>";
    body += "<p><a href='/fw'>Firmware (GitHub)</a></p>";
    body += "<form method='POST' action='/factory'><button type='submit'>Återgå till AP-läge (radera WiFi)</button></form>";
    body += "</div>";
    server.send(200, "text/html", htmlWrap("Device", body));
  });

  server.on("/fw", HTTP_GET, []() {
    loadGithubTarget();

    String body;
    body += "<h2>Firmware (GitHub Release)</h2>";
    body += "<div class='card'>";
    body += "<form method='POST' action='/fw/setrepo'>";
    body += "<label>Owner</label><input name='owner' value='" + ghOwner + "'>";
    body += "<label>Repo</label><input name='repo' value='" + ghRepo + "'>";
    body += "<button type='submit'>Spara repo</button>";
    body += "</form>";
    body += "<p class='muted'>Listar senaste release från <b>" + ghOwner + "/" + ghRepo + "</b>.</p>";
    body += "<p><a href='/fw/list'>Hämta fillista</a></p>";
    body += "</div>";
    server.send(200, "text/html", htmlWrap("Firmware", body));
  });

  server.on("/fw/setrepo", HTTP_POST, []() {
    String owner = server.arg("owner"); owner.trim();
    String repo  = server.arg("repo");  repo.trim();

    if (owner.isEmpty() || repo.isEmpty()) {
      server.send(400, "text/plain", "owner/repo saknas");
      return;
    }
    saveGithubTarget(owner, repo);
    server.sendHeader("Location", "/fw");
    server.send(302, "text/plain", "");
  });

  server.on("/fw/list", HTTP_GET, []() {
    loadGithubTarget();

    screen2("GitHub:", "Hamtar lista...");
    AssetInfo assets[20];
    size_t n = 0;
    String tag, err;

    bool ok = githubFetchLatestAssets(assets, 20, n, tag, err);
    if (!ok) {
      screen2("GitHub fel", err);
      String body;
      body += "<h2 class='err'>Kunde inte hämta lista</h2><div class='card'>";
      body += "<p>" + err + "</p>";
      body += "<p class='muted'>Tips: repot måste vara Public och ha en publicerad Release med assets.</p>";
      body += "<p><a href='/fw'>Tillbaka</a></p></div>";
      server.send(200, "text/html", htmlWrap("FW error", body));
      return;
    }

    String body;
    body += "<h2>Senaste release: <span class='muted'>" + tag + "</span></h2>";
    body += "<div class='card'>";
    body += "<form method='POST' action='/fw/flash'>";
    body += "<table><tr><th>Välj</th><th>Fil</th><th>Storlek</th><th>Downloads</th></tr>";

    bool firstBinSet = false;
    for (size_t i = 0; i < n; i++) {
      const bool isBin = assets[i].name.endsWith(".bin");
      body += "<tr>";
      if (isBin) {
        body += "<td><input type='radio' name='url' value='" + assets[i].url + "'";
        if (!firstBinSet) { body += " checked"; firstBinSet = true; }
        body += "></td>";
      } else {
        body += "<td class='muted'>—</td>";
      }
      body += "<td>" + assets[i].name + (isBin ? "" : " <span class='muted'>(ej .bin)</span>") + "</td>";
      body += "<td class='muted'>" + String(assets[i].size / 1024) + " KB</td>";
      body += "<td class='muted'>" + String(assets[i].dl_count) + "</td>";
      body += "</tr>";
    }

    body += "</table>";
    body += "<button type='submit'>Ladda ner &amp; bränn vald .bin</button>";
    body += "</form>";
    body += "<p class='muted'>Obs: bara .bin kan flashas på ESP32.</p>";
    body += "<p><a href='/'>Till enhetssidan</a></p>";
    body += "</div>";

    screen2("GitHub:", "Lista klar");
    server.send(200, "text/html", htmlWrap("FW list", body));
  });

  server.on("/fw/flash", HTTP_POST, []() {
    String url = server.arg("url");
    url.trim();

    if (url.isEmpty() || !url.endsWith(".bin")) {
      server.send(400, "text/plain", "Välj en .bin");
      return;
    }

    if (gOtaInProgress || gOtaTaskHandle != nullptr) {
      server.send(409, "text/html", htmlWrap("Busy",
        "<h2>OTA pågår redan</h2><div class='card'>"
        "<p>Vänta tills den är klar (se displayen).</p>"
        "<p><a href='/fw/list'>Tillbaka</a></p>"
        "</div>"));
      return;
    }

    server.send(200, "text/html", htmlWrap("Flashing",
      "<h2>Startar uppdatering...</h2><div class='card'>"
      "<p>Enheten laddar ner och flashar firmware.</p>"
      "<p class='muted'>Status syns på displayen. Enheten startar om automatiskt när det är klart.</p>"
      "</div>"));

    delay(50);

    String* heapUrl = new String(url);
    BaseType_t ok = xTaskCreate(
      otaTask,
      "otaTask",
      12288,
      heapUrl,
      1,
      &gOtaTaskHandle
    );

    if (ok != pdPASS) {
      delete heapUrl;
      gOtaTaskHandle = nullptr;
      gOtaInProgress = false;
      screen2("OTA fel", "TaskCreate fail");
      Serial.println("OTA: xTaskCreate failed");
    }
  });

  server.on("/factory", HTTP_POST, []() {
    server.send(200, "text/html", htmlWrap("Reset",
      "<h2>Återställer...</h2><div class='card'><p>Raderar WiFi och startar om.</p></div>"));
    delay(300);
    clearCreds();
    ESP.restart();
  });
}

// ---------------- Arduino ----------------
void setup() {
  Serial.begin(115200);
  delay(200);

  tft.init();
  tft.setRotation(5);
  tft.setBrightness(180);

  loadGithubTarget();
  screen2("Bootar...", "");

  if (loadCreds(staSsid, staPass)) {
    screen2("Ansluter till:", staSsid);
    if (connectSTA_only(staSsid, staPass, 15000)) {
      MDNS.begin("esp32c6");
      startDeviceRoutes();
      server.begin();
      modeState = MODE_STA_DEVICE;
      screen2("WiFi ansluten!", WiFi.localIP().toString());
      return;
    }
  }

  startCaptivePortal();
  startDeviceRoutes(); // /fw finns även när vi kör AP+STA under anslutning
}

void loop() {
  dns.processNextRequest();
  server.handleClient();

  if (apShutdownAtMs != 0 && millis() > apShutdownAtMs) {
    apShutdownAtMs = 0;
    dns.stop();
    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_STA);
  }

  static uint32_t lastCheck = 0;
  if (millis() - lastCheck > 3000) {
    lastCheck = millis();
    if (modeState == MODE_STA_DEVICE && WiFi.status() != WL_CONNECTED) {
      screen2("WiFi tappad", "forsoker igen...");
      WiFi.reconnect();
    }
  }

  delay(2);
}

/*
  Felsökning skärm:
  1) Om allt är svart men BL lyser:
       prova cfg.invert = false;
       prova cfg.rgb_order = true;

  2) Om bilden är förskjuten:
       prova cfg.offset_x = 34;

  3) Om inget syns alls:
       kontrollera att BL = GPIO23 och RST = GPIO22 verkligen stämmer med din pinout.
*/
