 -- FIRMWARE NETXT GENERATION

FIXA: UPPTÄCKTEN OM ATT UPPLÅSNINGSKOD I FIRMWARE 1.1623 HAR FELAKTIG UTRÄKNING AV TIONDELARNA GÄLLER ALLA FIRMWARE FRÅN 2013 (BEGYNNELSEN TILL VERSION 1706)
FIXA: DET BLIR INGET SPACE MELLAN "L" OCH "M" SYMBOLERNA OM DE VISAS SAMTIDIGT.
FIXA: SÅ ATT ÖVERGÅNGEN MELLAN UPHALNINGSFART OCH LINE MESS FART SKER MED MJUKARE ÖVERGÅNG KANSKE?
FIXA: OM MASKIN SÄTTS I FIRMWARE MOTTAGARLÄGE MEDAN EN MASTER SÄNDER SÅ VERKAR MOTTAGAREN FASTNA I NÅGOT KONSTIGT LÄGE OCH MÅSTE STARTAS OM. VILKET LÖSER PROBLEMET IOFS.
FIXA: RC4 - AUTO LEDDEN BLINKAR OM DEN INTE ÄR ASSIGNAD I TAKT MED NÄTVERKET. BLÅ LED BLINKAR OCKSÅ MEN INTE LITA OFTA.
KOLLA: I NÄSTA FIWMARE BÖR GRÄNSEN FÖR SNURR ANTAGLIGEN INTE JÄMFÖRAS MOT STRÖMMEN (VERDE[43] UTAN VEKT SOM ÄR VERDE[143]. MEN LABBA FÖRST !
KOLLA: TEXTER FÖR UTDRAG AV LINAN INNAN MOTORN STARTAR ELLER NAPPAR STÅR SOM ANTAL VARV. T EX Omdreining [E154 PP]. MEN DET RÄKNAS NUMERA OM TILL STRÄCKA.
FIXA: 2025-06-30 ETT MEXKORT KAN SKICKA PROGRAMMET TILL EN MEXMINI, MEN INTE TVÄRTOM !?
I NÄSTA FIRMWARE SÅ KAN MOTORNS GENERATION (G1/G2), SAMT VÄRDEN FÖR MIN OCH MAXFARTSKALIBRERING AUTOMATISKT JUSTERAS BEROENDE PÅ MOTORNS FART.

-- FIRMWARE 1.2503
ADDED: - DISPLAY - CONTRAST - PRESENT DISPLAY CONTRAST IS STORED INTO EEPROM WHEN RETAILER OR BELI MENU ARE ENTERED AND WILL BE THE FUTURE FACTORY SET VALUE.
ADDED: - MOTOR   - MORE - PREF - MOTOR GENERATION G1 OR G2 NOW STORES INTO MEX EEPROM AND WILL BE FACTORY SET VALUE.
ADDED: - MOTOR   - MORE - PREF - MINIMUM SPEED VALUE MOTOR NOW STORES INTO MEX EEPROM AND WILL BE FACTORY SET VALUE.
ADDED: PROTECTION SCREEN SHOWS ADDITIONAL DATA AT THE BOTTOM THAT CAN HELP FINDING THE PROBLEM

-- FIRMWARE 1.253x --
FIXED: TEXT NORWEGIAN "AUTO ÅTERSTART" > "OMSTART"
FIXED: TEXT ENGLISH "AUTO RESTART" > "RESTART"
FIXED: TEXT ENGLISH "BREAK" > "BRAKE".
FIXED: TEXT ENGLISH "BRAKE REDUCE" > "BRAKE REDUCTION".
FIXED: TEXT NORWEGIAN "VISA NAPPDYBDE EFTER OPDRAG" > "VIS NAPPDYBDE ETTER OPPHALING"

TESTA: TESTA SÅ ATT DISPLAYTEXTERNA FÖR DISPLAYENS LYSSTYRKA OCH SHOWTIME HAR KORREKTA TEXTER DÅ DESSA ÄR ÄNDRADE 
        1. BRIGHTNESS > POWER
        2. SHOWTIME > TIME
        3. MODE SKA STÅ BÅDE I NETWORK MODE OCH SAMMARBEID MODE
        4. ASSISTING TIME > TIME
        6. ÄNDRA ANTAL > ANTALL
        7. SVARSDELAY > FORSINKELSE

-- FIRMWARE 1.2525 DENNA FIRMWARE ÄR ÅTERGÅNG TILL 1.2502 MED PÅBYGGNAD AV SAKER FRÅN 2502A,B,C OCH D SAMT TIIDIGARE 1.2417.
FIX: AUTO PROGRAM POINTER (IV19) 8 MEMORY ADDRESSES CORRECTED.
FIX: NORWEGIAN TEXT "STORLEK" CORRECTED TO "STøRRELSE".
FIX: NORWEGIAN TEXT "OP" CORRECTED TO "OPP".
FIX: DISPLAY - BRIGHTNESS - MAXIMUM BRIGHTNESS IS LOWERED FROM 100%(250 OF 250 STEPS) TO 80% (200 STEPS) TO REDUCE DISPLAY BACKGROUND CURRENT FROM 160mA to 100mA.
FIX: FRÅN VERSION 1.2022 TILL 1.2025 SÅ ÖKADES LOWBATTTIMERNS VÄRDE FRÅN 1,5 SEKUNDER TILL 60,0 SEKUNDER INNAN LOWBATT INTRÄDER. NU ÅTERSTÄLLD.
FIX: PROTECTION SCREEN BLOCKED THE PROTECTION IN A WHILE(1) LOOP. NOW PROTECTION ACTIVATES BEFORE PRINTOUT.
FIX: FISH PROGRAM "FISHFINDING": DID NOT USE THE DEPTH REDUCTION. REPPORT FRÅN CHRIS 2025-06-10
FIX: FISH PROGRAM "STEP JIG": REMOVAL STEP JIG PAUSE AT LAST PULL WHEN JIG LENGTH WAS REACHED. NOW RETURNS DOWN DIRECTLY WHEN REACHED WITH NO PAUSE.

-- FIRMWARE 1.2502 --
FIX:     - MENU - TEXT 	   - "WHEEL PULSES" changes to "WHEEL LAPS"
FIX:     - THEIF CODE 	   - SOME SERIAL NUMBERS UNTILL NOW COULD GENERATE OVERFLOW WHEN CALCULATING THE UNLOCK CODE SO MACHINES CAN'T BE UNLOCKED.
CHANGED: - FISHING PROGRAM - TROLLING - CATCH TIME DOWN IS AVAILIABLE
CHANGED: - LMESS.  	   - EARLIER DELAY FOR ACTIVATING LINE MESS WAS A DISTANCE.NOW THAT IS CHANGED TO A "DELAY TIME"{"AKIVERES NbR VEKT FALLER UNDER","ACTIVATES WHEN WEIGHT GOES BELOW"},   // 201
CHANGED: - LMESS.  	   - SAME TIME AS THE CHANGE ABOVE THE DELAYTIME FOR AVTIVATE THE LINE MESS ALSO REPLACES THE FIXED DELAY OF 2 SECONDS FOR MOTOT START DELAY BEFORE ANY FUNCTION IS ACTIVATED. LIKE CATCH DETECTION AND REGULATION.
FIX:     - MOTOR  	   - LMESS.  THE VALUE FOR THE MINIMUM MOTOR LOAD FOR ACTIVATE LINE MESS HAS BEEN COMPARED TO THE MOTOR CURRENT, BUT IS NOW COMPARED TO CALTULATED WEIGHT. 0,0-10,0 IS ALSO CHANGED IN DISPLAYED TO 0-100%
CHANGED: - TEXT   	   - LMESS.  {"TID EFTER MOTORSTART.","ACTIVATE AFTER MOTOR STARTS."},                  // 254
CHANGED: - TEXT   	   - LMESS. {"AKIVERES NbR VEKT FALLER UNDER","ACTIVATES WHEN WEIGHT GOES BELOW"},   // 201
ADDED:   - MENUe  	   - CATCH - A NEW SUB MENU FOR CATCH [E3] IS IMPLEMENTED TO DEVIDE THE 9 CATCH PEAGES IN TO THE SUB PAGES "UP / DOWN / SHOW / RESTART" 

 -- FIRMWARE 1.2450
FIX:    - NETWORK 		- TIMEOUT 					- THE TIMEOUT WAS SHOWED AS SECONDS BUT WAS INFACT 1/5 SECONDS. NOW IT SHOWS CORRECT AND OLD MAXIMUM SETTING 9.9 (WAS 9.9/5=1.98S) IS NOW 299 (8 SECONDS)
FIX:    - NETWORK 		- REMOTE KEYBOARD 				- REMOTE KEYBOARD COMMANDS ARE PREVENTED TO RELAY FURTHER TO SHOWN AND CHOOSEN EX'S IF GROUP PICTURE ARE SHOWED.
CHANGE: - NETWORK 		- REMOTE KEYBOARD				- EX NOW ACCEPTS RC4 UP BUTTON COMMAND ABOVE SURFACE (LINE OUT=0) BUT STILL REJECTS THE COMMAND IF IT'S SENT FROM OTHER EX.
CHANGE: - DISPLAY 		- MENUES 		- NETWORK		- RENAME "ON" TO "RC4" FOR GROUP D, E AND F.
CHANGE: - DISPLAY 		- TEXT			- NETWORK 		- THE ERRORS DID SHOW ONE AT A TIME AND STEPPED THROUGH WITH BUTTONS [3] AND [6]. NOW ALL ERRORS SHOWS IN ONE PICTURE. SHOWS IN ADVANCED MENU DETAIL LEVEL ONLY
CHANGE: - DISPLAY 		- MENUES 		- NETWORK		- GROUP PICTURE SHOW GROUP D,E AND F ONLY WHEN MENU DETAIL LEVEL IS SET ADVANCED.
CHANGE: - NETWORK 		- PROTOCOL 					- START BYTES ARE CHANGED FROM "1", "7", "0" SO THE DATA CAN BE VISIBLE TO PC/MAC
ADDED:  - NETWORK 		- REMOTE KEYBOARD 				- WHEN REMOTE KEYBOARD COMMANDS ARE REJECTED (ABOVE LITE IS ABOVE SURFACE OR GROUP PICTURE SHOWS) THE BEEPER SOUNDS FAST 3 TIMES.
ADDED:  - NETWORK 		- FIRMWARE 					- TIME FOR FIRMWARE UPDATE SHORTENS DOWN TO 80 SECONDS.
ADDED:  - NETWORK 		- NETWORK CHECK					- THE LED'S ON RC4 NOW SHOWS IF THERE IS ANY MASTER SENDING OUT HEART BEATS.
CHANGE: - MENUES 		- TEXT 						- E615 "HJELP" RENAMED TO "MENUES"
CHANGE: - MENUES 		- PLACEMENT 					- E615 "SHOW WHEEL STATUS SYMBOL" IS MOVED TO MENU E614 AS E614P.
CHANGE: - MENUES 		- TEXT 						- E614 "VISTID" RENAMED TO SHORTER TEXT "VISE".
CHANGE: - MENUES 		- TEXT						- E654 "MENUES" REMOVED. UNDERLAYING PICTURE.... SE BELOW.
CHANGE: - MENUES 		- PLACEMENT 					- E654 "MENUE DETAILS" MOVED TO DISPLAY MENU E615 AS E615P.
ADDED:  - CATCH 		- REGISTRATION 					- ON LINE PULLOUT - ENABLED IN ALL FISHING PROGRAMS AND NOW EVEN IN PAUSES.
ADDED:  - CATCH 		- REGISTRATION 					- MOTOR SPEED - THE MOTOR SPEED SENSOR DEPENDS ON THE MOTOR AND MEX GENERATION. A PICTURE E152PPPP NEEDED TO BE SET ACCORDING TO.E152 PP MODEL GENERATION
ADDED:  - BOOST VOLT 		- PROTECTION 					- FOR INTERNAL (BOOST) OVERVOLTAGE AT 45 VOLT. DISCONNECTS WHEEL FROM MOTOR WITH WARNING DISPLAY. REACTS ON HIGH BOOST VOLTAGE, EMERGENCY STOP SWITH DEACTIVATION AND AT STARTUP OF THE MACHINE.
ADDED:  - MENUES 		- INFO 						- SUB MENU FOR E62 INFO. TEXTS "VOLT STRÖM FUKT", "TEMP FART S/N" /  "TEMP FART  S/N  ","TEMP SPEED  S/N "
ADDED:  - MENUES 		- INFO 						- THE NEW SUB MENU UNDER E62 HAS 6 OPTIONS AND EXCLUDES "RET" FUNCTION. ADDING POSSIBILLITY TO PRESS PROG BUTTON  FOR E62 MENU. AS "RET" SUBSTITUTE.
ADDED:  - HUMIDITY 		- WARNING 					- IN THE NEW MENU E623 "HUMID" THERE IS NOW WARNINGS FOR HIGH HUMIDITY WITH LEVEL CONTROL. LEVEL 100% DISABLES THE WARNING. FACTORY 80%. WARNING LEVEL IS SHOWN ONLY WITH MENU LEVEL SET TO ADVANCED AND NOT IN NORMAL OR SIMPEL.
FIX:    - DISPAY 		- GROUP PICTURE 	- KEYBOARD 		- PREVENT BUTTONS TO CHANGE VALUES IN GROUP D,E AND F. THE VALUES ARE SET AUTOMATICALLY WHEN RC4 ATTENDS TO THE NETWORK
ADDED:  - MEMORY 		- EEPROM 		- VERIFY 		- ERROR CHANGES THE FLASHING STATUS SYMBOL "W" TO AN "E". VALUES ARE NOT CORRECT SAVED IF SHOWN.
FIX:    - TEXT 			- NORWEGIAN TEXT 	- COOPERATION 		- "BÅDE OG" FOR COOPERATION MODE  REPLACED WITH "SPØR OG HJELP" OR "ASK AND HELP".
FIX:    - TEXT 			- NORWEGIAN TEXT 	- COOPERATION 		- "BÅDE OG" FOR SOUNDER REPLACED WITH "LOKALT OG EKTERNT" OR "LOCALT AND EXTERNAL" .
FIX:    - TEXT 			- NORWEGIAN TEXT 	- COOPERATION 		- "BÅDE OG" FOR LOCK MODE REPLACED WITH "ALLTI" OR "ALWAYS".
ADDED:  - MENUES 		- WHEEL LOCK		- ACTIVATION 		- E445 VALUES FOR "MOTOR LOCK" EXTENDS FROM ONLY THE TWO CHOISES OFF AND MANUAL TO FOUR CHOISES OFF, MANUAL, AUTOMATIC AND ALWAYS.
ADDED:  - MENUES		- TROLLING PROGRAM 	- WHEEL PULLS OUT 	- NOW ALSO SHOWS THE PICURE FROM CATCH MENU "CATCH IF WHEEL IS PULLED OUT" WHEN SCROLLING THROUGH THE FISHING PROGRAM WITH THE PROG BUTTON.
CHANGE: - CATCH 		- REGISTRATION 		- TROLLING PROGRAM 	- THE PICURE "MOTOR START IF FISHINGLINE PULLS OUT" CAN BE SET TO 0 (OUT) THAT INHIBITS MOTORSTART WHEN LINE IS PULLED OUT.
CHECKE: - HOOKING ZONE		- AUTOSTART AT STOP AT PULLEY 			- REPORT THAT THE "RESTART TIME" OR "STOP IN HOOKING ZONE" (NEW NAME)  IS MISSING IN THE MENU IS TRUE BECAUSE ITS FIXED TO 0 SECONDS BECAUSE STOP IN THE HOOKING ZONE IN AUTOMATIC MODE ALWAYS RESTARTS THE FISHING PROGRAM.
CHANGE: - DORGING PROGRAM 	- TEXT 						- THE OLD TEXT "TROLLING LAPS" CHANGES TO "TROLLING START MOTOR IF WHEEL IS PULLED OUT".
CHANGE: - CATCH 		- REGISTRATION 		- WEIGHT 		- USER CAN NOW CHOOSE IF MOTOR CURRENT SHALL ADD TO THE WEIGHT VALUE FOR CATCH DETECION. ADDING PICTURE [E3 PPP PPP] WITH OPTIONS (YES/NO).
ADDED:  - CATCH 		- REGISTRATION		- WEIGHT 		- USER CAN NOW CHOOSE IF DROPPED MOTOR SPEED DUE TO HIGHER LOAD SHALL ADD TO THE WEIGHT VALUE FOR CATCH DETECTION. ADDING PICTURE [E3 PPP PPP P] WITH OPTIONS (0=OFF, 1=FAST REACTION TO 99 = SLOWEST REACTION)
ADDED:  - CATCH 		- REGISTRATION 		- WEIGHT 		- USER CAN NOW CHOOSE IF DROPPED WHEEL SPEED DUE TO HIGHER LOAD SHALL ADD TO THE WEIGHT VALUE FOR CATCH DETECTION. ADDING PICTURE [E3 PPP PPP PP] WITH OPTIONS (0=OFF, 1=FAST REACTION TO 99 = SLOWEST REACTION)
ADDED:  - MOTOR 		- MINIMUM SPEED 	- 			- E152PPP MINIMUM SPEED ADJUST" IS ADDED TO THAT MAKES IT POSSIBLE TO MATCH MOTOR SPEED TO SET VALUES IS DISPLAY.
CHANGE: - INFO 			- WHEEL SPEED 					- FOR MORE STABLE VALUE ESPECIALLY WHEN INVOLVED AS SENSOR FOR WEIGHT THE VALUE (WHEEL SPEED) IS FROZEN FOR EATCH MAGNET PULS AND CLEARED TO 0 WHEN SPEED IS BELOW 20,34 RPM
CHANGE: - RESET 		- MULTI LANGUE SETUP	- PICTURES 		- EXTENDS FROM ONLY CHOISE A OF LANGUAGE TO A SERIES OF SHOWED PICTURES THAT NEEDS TO BE STEPPED THROUGH BEFORE MACHINE STARTS UP.
CHANGE: - RESET 		- MULTI LANGUE SETUP 	- PICTURES 		- DISPLPAY CONTRAST AND LIGHT IN THE NEW MULTI LANGUAGE SETUP IS FIXED TO FACTORY SET LEVELS.

--  FIRMARE VERSION  1.2238 --

-- FIRMARE VERSION  1.2152 --
FIX: 	- MOTOR LOCK 								- THE "L" CHARACTERS FOR ACTIVATED "MOTOR LOOK" WERE SHOWN EVEN IF MOTOR LOCK WAS DEACTIVATED UNTILL PRESSING STOP/UP/AUTO/ZERO BUTTON. NOW ITS REMOVED AT ACTIVATION
FIX: 	- BIG CHARACTERS							- IF AUTOMATIC PROGRAM IS STARTED AND IF "BIG CHARACTERS" IS DISABLED BEFORE THE TIMER RUNS OUT THE SCREEN WILL BE BLANK, SHOWS NOTHING.
FIX: 	- WHEEL SENSOR 								- TEST PICTURE DID SHOW VALUES ABOVE THE ZEROPOINT (NEGATIVE VALUES) WRONG WITH STRANGE CHARACTERS.
ADDED: 	- MOTOR 								- MOTOR ACTUALLY SPEED RANGE 30-180 RPM RESPONDS TO DISPLAYED VALUE 30-110 (THE 110-180 HAS NO AFFECT, SCALE ERROR ABOUT 40%). NEW PARAMETER E152PP "MOTOR - MAXIMUM SPEED TUNING" IS ADDED AND VALUE ABOUT 92% MAKES 30-180 WORK FINE.
CHANGE:	- MOTOR 								- WHEN MOTOR SPEED NOW IS TUNED WITH THE NEW PARAMETER ABOVE, THE "SPEED IN HOOKING ZONE"(OLD NAME "MINIMUM SPEED") IS ALSO REDUCED WITH 40% WHICH IS A  BIT TOO LOW. FACTORY SETTING RAISES TO 50 RPM.
 
-- FIRMWARE VERSION 1.2150 --
CHANGE:	- COOPERATION		- MACKERELL PROGRAM				- COOPERATION ALSO NOW IN MACKEREL PROGRAMS WITH SYNCHRONIZED LINES WHEN HAULING UP.
ADDED:	- COOPERATION		- CATCH MEMORY 					- SHARED DEPTH AND JIG LENGTH IS RENEWED EVEN IF CATCH IS DETECTED BY MACHINE HOLDING CATCH MEMORY.
ADDED:	- COOPERATION		- PRIORITY 					- IF REMAINING TIME FROM "ASSISTING TIME"[E]652P (VISIBLE IN MASTER MACHINE ONLY) IS LESS THEN 5 SECONDS IN DIFFERENCE TO OTHER MACHINES. HIGHEST NETWORK ID PULLS UP FIRST.
CHANGE:	- COOPERATION		- AUTO PAUSE					- AUTO PAUSE EXTENDS FROM 10,0 TO 999,9 SECONDS. ALLOWED MACHINES TO START NOT SYNCED BUT WITH ONE PRESS ON AUTO BUTTON ON REMOTE CONTROL
FIX:	- DISPLAY		- EXTRA DRAG AT CATCH				- THE PICTURE FOR EXTRA DRAG AT CATCH E12PP HAD GRAPHICAL ERROR AT LINE 3. MAKES VAULES OVERWRITTEN WITH TEXT "DRAG BUTTONS..."
FIX:	- DISPLAY		- EXTRA DRAG HAUL UP				- THE PICTURE FOR EXTRA DRAG WHEN HAULING UP E13PP HAD GRAPHICAL ERROR AT LINE 3. MAKES VAULES OVERWRITTEN WITH TEXT "DRAG BUTTONS..."

-- FIRMWARE VERSION: 1.2148 --
FIX: - CATCH - USING AUTO MODE RESTART BY TIMER [E]3PPPP "RESTART" PROHIBITED FURTHER CATCH DETECTION POSSIBILITIES. FIXED.
FIX: - CATCH - "CATCH DEPTH MEMORY" CONTROLLED FISHING DEPTH EVEN WHEN NOT USED IN NETWORK OR SET TO ASK FOR HELP. FIXED.
FIX: - BOTTOM FISHING PROGRAM - THE "BOTTOM DISTANCE" WAS SKIPPED IF LINE REACHED SET "DEPTH". FIXED 
FIX: - GENERAL - MOTOR DID NOT STOP AT ZERO POINT EVERY TIME IN AUTO MODE.
FIX: - DISPLAY - SCRAP PICTURE WAS FOUND IN MENU [E]652 IF "MENU LEVEL" [E]654 WAS SET TO "NORMAL" AND "NETWORK MODE" [E]651 WAS SET TO "SLAVE". REMOVED.
FIX: - CPU - THE CLOCK FOR ALL TIMERS NOW HAS BETTER TIME BASE.
NEW: - HOOKING ZONE - "HOOKING ZONE" IS A LOW SPEED ZONE FROM THE ZERO POINT AND BELOW. HOW DEEP IT GOES DOWN IS SET IN [E]653 "HOOKING ZONE
NEW: - HOOKING ZONE -IN HOOKING ZONE THE MOTOR SPEED IS SET BY [E]154 "HOOKING ZONE
NEW: - HOOKING ZONE -IN HOOKING ZONE WHEEL BRAKE SPEED IS TAKEN FROM [E]53 "HOOKING ZONE
CHANGE: - CATCH - "CATC TIME DOWN" IS MOVED FROM MENU [E]3P TO FISHING PROGRAM P-MENU WHITHOUT BOTTOM PROGRAM. 
CHANGE: - AIR BRAKE - THE ZONE "AIR BRAKE" [E]53 IS NOW CONTROLLED BY "HOOKING ZONE" [E]653 AND THEREFORE RENAMED "HOOKING ZONE - MAX WHEEL SPEED"
CHANGE: - AIR BRAKE - CATCH DETECTION BY "AIR BRAKE" ACTIVATION IS NOT REALISTIC. REMOVED.
CHANGE: - COMMUNICATION - IMPROVED COMMUNICATION, GLOBAL PARAMETERS ARE SENT IN ALL MESSAGES.
CHANGE: - COMMUNICATION - MACHINES ALREADY BEEING AT SURFACE OR ABOVE DOES NOT START MOTOR TO ANY NETWORK COMMAND.
CHANGE: - COMMUNICATION - FIRMARE CAN NOW BE SENT ONLY IN SINGLE MODE. MULTIPELE UPDATE IS NOT LONGER POSSIBLE.
CHANGE: - DEPTH BRAKE - CATCH DETECTION BY "DEPTH BRAKE" ACTIVATION IS NOT REALISTIC. REMOVED.
CHANGE: - DISPLAY - WHEEL SPEED READING IMPROVED.  
CHANGE: - DISPLAY - ANALOGUE BASED VALUES CHANGES TOO OFTEN TO BE READ. NOW UPDATED IN DISPLAY 3 TIMES PER SECOND.
CHANGE: - DISPLAY - THE MINUS SIGN BEFORE "LINE OUT" VALUE HAS NOW FIXED POSSITION IN THE DISPLAY.
CHANGE: - DISPLAY - VAULES AND SYMBOLS ARE NOW WRITTEN TO DISPLAY ONLY WHEN CHANGED. SPEEDS UP PROGRAM FROM 20 FRAMES PER SECONDS TO 200.
CHANGE: - DISPLAY - PICTURES FONTS CHANGES....- MENUES. UPPER AND LOWER LINES SHOWS WITH 16 CHARACTERS. BOLD FONT. - NORMAL PICTURES. UPPPER LINE 16 CHARACTERS LONG. BOLD FONT. SECOND LINE 32 CHARACTERS LONG. NOT BOLD FONT. - NORMAL PICTURES. VALUES SHOWS AUTOMATICALLY WITH 16 CHARACTERS BOLD, OR 32 CHARACTERS LONG, NOT BOLD IF TEXT IS LONGER THEN 16 CHARACTERS LONG.
CHANGE: - FISHING LINE / WHEEL - SETTINGS FOR "WHEEL WIDTH" [E]41 EXTENDS FROM BETWEEN 50-200 MM TO 1-999 MM.
CHANGE: - FISHING LINE / WHEEL - SETTINGS FOR "WHEEL LINE OUTER DIAMETER" [E]42P EXTENDS FROM BETWEEN 130-400 MM TO 15-500 MM.
CHANGE: - FISHING LINE / WHEEL - SETTINGS FOR "LINE DIMETER" [E]43 IS EXTENDS FROM BETWEEN 1,0 - 5,0 MM TO 0,01 TO 9,99 MM.
CHANGE: - FISHING LINE / WHEEL - SETTINGS FOR "LINE DIMETER" [E]43 IS NOW MADE IN 0,01 STEPS.
CHANGE: - FISHING LINE / WHEEL - ALL SETTINGS BASED ON WHEEL LAPS IS NOW MADE IN LENGTHS UNITS (FEET-METER-FATHOMS) WITH DECIMALS. 
CHANGE: - FISHING LINE / WHEEL - WHEN, AND IF WHEEL GET S TUCKED (FUNCTION STOP IN SEA, AND STOP IN HOOKING ZONE IS NOW RETRIGGED ON EVERY WHEEL PULSE. EARLIER A WHOLE WHEEL LAP WAS NEEDED BOFORE MACHINE FELT THAT WHEEL WAS "MOVING".
CHANGE: - MACKEREL PROGRAM - "SOFT STOP" TO "ZERO POINT" WAS NOT POSSIBLE IN MACKERELL PROGRAMS. NOW THEY ARE. HOWEVER THE SOFT STOP BEGINNS ALREADY TO "HOOKING ZONE" [E]653 IN AUTO MODE, AND IF USED. 
NEW:    - MACKEREL PROGRAM - "LINE TANGLE" [E]151 NOW AVAILABLE ALSO IN MACKEREL PROGRAM. THE CATCH DETECTION WILL NOT SHOW, BUT ALLOWES MOTOR TO SPEED UP AND HAUL IN FASTER IF LINE IS SLACKED IF FISH TAKES THE HOOKS AND SWIM UPWARDS SO MOTOR CURRENT IS TOO LOW. GOING BACK TO HAUL UP SPEED IF MOTOR CURRENT GETS NORMAL AGAIN.
CHANGE: - MACKEREL PROGRAM - COOPERATION WAS NOT WORKING AS IT SHOULD IN MACKEREL PROGRAM
CHANGE: - MACKEREL PROGRAM - MINIMUM DEPTH IN MACKEREL PROGRAMS CHANGES FROM 0 TO 1
CHANGE: - CPU - THE CLOCK FOR ALL TIMERS NOW HAS BETTER TIME BASE
CHANGE: - MEMORY - VALUES ARE SAVED TO MEMORY DIRECTLY ON CHANGE. NO NEED TO ENTER MAIN PICTURE. AND THE "W" IN MAIN PICTURE WILL THEREFORE NOT BE SEEN.
CHANGE: - HAULING UP MENU E13 - "HAULING UP MODE - TRANSITION TIME" [E]13P IS RENAMED TO "HAULING UP MODE - MOTOR START TIME". AS IN OTHER MOTOR MENUES.
CHANGE: - HAULING UP MENU E13 - PICTURE FOR HOW MUCH LINE IS ALLOWED TO BE PULLED OUT BEFORE MOTOR STARTS AGAIN WHEN MOTOTR IS STOPPED IN "HAULING UP MODE", IS REMOVED. THE REASON IS THAT MOTOR SHALL START IMEDIATELLY IF LINE IS PULLED OUT. IN ADDITION, "WHEEL LAPS BEFORE MOTOR STARTS" IS ADDED IN MENU [E]154PP "HOOKING ZONE", THAT IS ACTIVE ONLY IN THE "HOOKING ZONE" AREA
CHANGE: - WHEEL LOCK	- USING THE MOTOR START TO WIND UP LINE IF PULLED OUT, CALLED "PAUSE MODE", IS REPLACED WITH "WHEEL LOCK". SE BELOW CHANGES.
CHANGE: - WHEEL LOCK	- MENU TEXT "PAUSE" [E]445 IS REPLACED WITH "LOCK".
CHANGE: - WHEEL LOCK	- "PAUSE MODE" [E]445 RENAMES TO "LOCK MODE"
CHANGE: - WHEEL LOCK	- SETTINGS FOR OLD "PAUSE MODE" ("NEVER" / "AT STARTUP" AND "WITH BUTTON UP") IS REPLACED WITH "NEVER" AND "MANUAL MODE"
CHANGE: - RP-PULSES	- "NUMBER OF PULSES" [E]45PP FOR RP-CARD IS FACTORY SET TO 3 (BEFORE 0), AND THE STRENGTH CHANGES TO 30% (BEFORE 10%). THIS WILL DEMAGNITIZES THE ELECTROMAGNETIC CLUTCH WHICH RELEASES THE WHEEL MUCH BETTER THEN BEFORE.
CHANGE: - SPEED BRAKES	- FACTORY DEFAULT VALUE FOR "SPEED BRAKE - FORCE" [E]51 WAS 10% AND IS TOO WEAK. CHANGED TO 30%.
CHANGE: - SPEED BRAKES	- DURING THE TIME WHEN ANY SPEED BRAKE IS ACTIVARED THE BOTTOM TIMER AND CATCH DOWN TIMER IS PAUSED. THIS WILL PREVENT ANY SPEED BRAKE STOP TO FAULTY ACTIVATE CATCH DOWN OR BOTTOM DETECT
CHANGE: - SPEED BRAKES	- WHEN RP PULSES ARE APPLIED THE BOTTOM TIMER AND CATCH DOWN TIMER IS PAUSED. THIS WILL PREVENT RP TO FAULTY ACTIVATE CATCH DOWN OR BOTTOM DETECT
CHANGE: - STOP AT PULLEY- FUNCTION "STOP AT PULLEY" IS NOW RETRIGGED ON EVERY WHEEL PULSE. BEFORE A WHOLE WHEEL LAP WAS NEEDED.
CHANGE: - STOP AT PULLEY- THE AREA OR ZONE FOR WHERE "STOP AT PULLEY" CAN BE ACTIVATED IS NOW SAME AS THE HOOKING ZONE - CHANGES IN MENUES, SEE "- HOOKING ZONE AND MENU E653-" 
CHANGE: - STOP IN SEA 	- MAXIMUM MOTOR RUN TIME "STOP AT SEA" [E]442 INCREASES FROM 99 SECONDS TO 999 SECONDS. ALSO SEE CHANGES ABOVE TIME CALCULATION IN SECTION - FISHING LINE / WHEEL - ABOVE.
CHANGE: - STOP IN SEA 	- FUNCTION "STOP IN SEA" IS NOW RETRIGGED ON EVERY WHEEL PULSE. BEFORE A WHOLE WHEEL LAP WAS NEEDED.

-- FIRMWARE VERSION: 1.2134-BL3 --
No info yet

-- FIRMWARE VERSION: 1.2109-BL2 --
MOTOR LOCK

-- FIRMWARE VERSION: 1.2107-BL2 --
Icelandic version

-- FIRMWARE VERSION: 1.2040-BL2 --
FIXED: - WHEEL LOCK	- 				- "The ""Wheel lock"" function introduced in firmware 1.2028 (also in 1.2035) has a seriouse startup fault. When power up Ex the lock direction is not initilized. It remains so untill the motor is started. The result of this is that the startup ""lock force"" that is meant to prevent wheel from rolling out, now instead pushes the motor out! It's a weak force though and the wheel does not always start. But if it starts it does not stop! Slowly winding out all the line. To prevent this the customers can just start and stop the motor by pressing Up and Stop after the machine is powered up. This initializes the wheel lock direction.  Removing the weight in the line when not used, so no helping weight is pulling the line out at next start up is also good idea."

-- FIRMWARE VERSION: 1.2035-BL2 --
CHANGE: - COOPERATION	- MENUES 			- Menu for network settings [E651] are spitted into 2 menues. [E651] NETW. will remain pictures for the communication it self, like address, master/slave and timing.  Pictures for cooperation are moved to [E652] COOP.
CHANGE: - COOPERATION 	- JIGG INSTEAD OF SLOW DOWN  	- Until now a machine that detects catch can be set to slow down to minimum speed by "Wait for hooks" to wait for other machines to join the catch area (the area is calulated as depth where the fish is detected +/- half jig length). A problem with slowing down is that fishes are often lost and hooks comes up empty. Now the solution is to let machines continue jig with normal speed untill machines are joining the catch area. Even though they continue jigging they will  indicate catch as before, but haul up only when they are allowed to. So some new pictures to controll this...
CHANGE: - COOPERATION 	- MINIMUM MACHINES  		- MINIMUM AMOUNT OF MACHINES KEPT IN CATCH AREA [E652 PP] With this the user can decside how many machines that must have joined to it's catch area before it starts hauling up. The number is default set to 0, and maximum is 5 other machines (all the other mahines in the group of maximum 6).
CHANGE: - COOPERATION 	- MAXIMUM MACHINES 		- MAXIMUM AMOUNT OF MACHINES HAULING UP [E652 PPP] Also how many machines that simultaniouse  are allowed to  haul up can be adjusted/limitied. To keep this value to only 1 or 2 machines can reduce amount of fish at surface, to reduce problem with seagulls and even seals.
ADDED:  - COOPERATION 	-  PRIORITY 			- "PRIORITY JIG MODE VS CATCH MODE [E652 PPP P]  This picture tells Ex how machines shall be excluded in cooperation formulas when communcation is lost.  Machines that is Hauling up is in Catch mode. Helping machines is in Jig mode. Se below lines CATCH 1 TO 4.
ADDED:  - COOPERATION 	- PRIORITY 			- Catch 1 - Jig 4  will first reduce all machines in Jig  mode down to 0 before machines in Catch mode is reduced.
ADDED:  - COOPERATION 	- PRIORITY    			- Catch 2 - Jig 3  will reduce one machines in Jig mode first, then one in Catch mode, and so on.  Jigging machines will be kept 1 less then machines in Catch mode.
ADDED:  - COOPERATION 	- PRIORITY 			- Catch 3 - Jig 2  will reduce one machines in Catch mode first, then one in Jig mode, and so on.  Catch machines will be kept 1 less then machines in Jig mode.
ADDED:  - COOPERATION 	- PRIORITY  			- Catch 4 - Jig 1  will first reduce all machines in Catch mode down down to 1 before machines in Jig mode are reduced."
CHANGE: - COOPERATION 	- WAIT FOR HOOKS		- The option "Wait for hooks" is also removed from the firmware.
NEW:  	- COOPERATION 	- MASTER VALUES 		- The pictures for cooperation rules above is only visible in master machine and when changed they will be transfered to all other machines. Pictures might also be hidden depending on choosen Menu level [E654] MENUES.
CHANGE: - COOPERATION 	-				- Improved communication. When machines were displaying group pictures the program were running to slow due to graphics. Now it's fast as when showing any other picture.
ADDED:  - COOPERATION 	-				- New picture under menu E651 NETW is the ATTEMTS TO REACH MACHINES  BEFORE DISABLED. This lets the master to make several attemt to contact a slave before it's marked as lost/disconnected. This makes a huge difference in stable communication.

-- FIRMWARE VERSION: 1.2028-BL2 --
ADDED:  - WHEEL LOCK 	- 				- The biggest news is the possibility to lock the wheel ("Wheel lock" or "Hjullås" in Norwegian) so no line is slipped out when machine is in Manual mode. Especially interesting for user with Angelvinsj. "Wheel lock" is implemented in the program as the 3th value for Pause mode. To activate "Wheel lock" enter [E445] and press button [3] up to 3 times.
ADDED:  - WHEEL LOCK	- 				- When "Wheel lock" is activated the motor consumes current to hold the wheel still, but it will never start rotate. Therefore a sound in the motor and electronic can be heard . The motor current , sound and torque  is in proportion to the DRAG (SLUR) setting. More DRAG power will get more power when wheel is locked. The power is much less then when motor is running, but the factory setting will hold several kilos at speed of several knots. Consuming 1-1,5Ampere only.
ADDED:  - WHEEL LOCK	- 				- There are some new pictures fine tuning Wheel lock if the factory setting is not good. Se 
ADDED:  - WHEEL LOCK 	- 				- [E445] Choose WHEEL LOCK (HJULLÅS)  as value for PAUSE MODE - ACTIVATES (PAUSE MODE - AKTIVERT)"
ADDED:  - WHEEL LOCK	- MINMUM FORCE 			- [E445 P] MINIMUM FORCE (LÅSEFAKTOR STARTVERDIE) This is how much extra force that will be sent when DRAG (SLUR)  is 0%.
ADDED:  - WHEEL LOCK	- MAXIMUM FORCE			- [E445 PP] MAXIMUM FORCE (LÅSEFAKTOR STARTVERDIE)This is how much extra force that will be sent when DRAG (SLUR)  is 100%.
ADDED:  - WHEEL LOCK	- TIME				- [E445 PPP] TIME (TID)This is the delay from when wheel stops to when force is applied. To short time will make the motor role over and not stop as it should.
CHANGE: - MENUES     	- FONT 				- Many texts has been rewritten with upper case letters.
ADDED:  - BOOTLOADER	- 				- Firmware 1.2028 also comes with the BootLoader or Bios version 2 (BL2) This makes it possible for the machine to receive new firmware in the future simultaneously as with other machines. All machines with BL2 can be upgraded with just one send command. BL2 starts up with showing a simple line (not rectangle) and will then show one or two rectangles when receiving data depending on if the sending machine is set to program 1 or many machines.

-- FIRMWARE VERSION: 1.2025-BL2 --

-- FIRMWARE VERSION: 1.2019-BL2 --
ADDED:	- FIRMWARE	- BOOT LAODER 			- SUPPORT FOR BOOTLOADER 2
ADDED:	- FIRMWARE	- BOOT LOADER			- FIRST FIRMWARE WITH REMOTE KEYBOARD (RK) LATER CALLED RC4

-- FIRMWARE VERSION: 1.1945-BL1 --
FIX: 	- BOTTOM FISHING 	- MINIMUM BOTTOM PAUSE	- Minimum "Bottom pause" is not 0,5 seconds, as showed in display.  In program 1.1922 (and perhaps in earlier firmare) the "Depth pause" was faulty added to "Bottom pause" which  extended the "Bottom pause" (Bottom detect time) to minmum time to 1,5 seconds.
FIX: 	- MOTOR             - STOP COMMAND          - PROBLEM WITH STOPPING THE MOTOR WITH THE STOP BUTTON. READ BELOW. 
FIX: 	- MOTOR             - STOP TIME             - Motor "Stopp time" (Factory set 0,7 sec) could be set to OFF, which make it hard to stop the motor.  Now minimum is 0,1 seconds.
FIX: 	- MOTOR             - START AT STOP POINT	- Motorn starts when STOP button is pressed and line is pulled out. When STOP button is held and line goes out the motor did start if "Pause mode" were used because the virtual stop point did not update while key was pressed. 
CHANGE:	- DISPLAY           - BIG FONT              - The text strings "Out", "50%" and "100%" for choosen font size for LINE OUT  does not cover eachother. Corrected.
CHANGE: - BOTTOM FHISHING	- BOTTOM PAUSE          - Minimum "Bottom pause" changes from 0,5 to 0,3 seconds.
CHANGE: - NORMAL FHISHING	- DEPTH PAUSE           - Minimum "Depth pause" changes from 1,0 to 0,3 seconds.
CHANGE: - WHEEL TIMER		- TIME DOWN             - A fixed 1.0 second delay time has always been added to the "Bottom pause" and "Catch down" when wheel starts going down. This time is now replaced with the "RP-Wheel time" (Factory set to 0,8 sec) which makes it possible to adjust the time  for better Bottom detection and Catch down function.
CHANGE: - TEXT              - MINMUM SPEED          - Two pictures under menu MINSPEED (E154) , the "Softstart" (E154P) and "Wheel laps" (E154PP) is associated with the Hauling up mode and is therefore moved to the Motor sub menu HAUL (E13). Factory settings are Softstart 5,0 sec and Wheel laps 0,3.?
New: 	- PAUSE MODE        - MENU                  - pause mode (E445) has got it own settings for Motor speed (E445P) and Softstart(E445PP). This makes it possible to have different line length to be payed out before motor starts to haul in, in PAUSE MODE. While in AUTO MODE the settings under menu MOTOR - HAUL is used (Se above note Changes - 5) . And when STOP is pressed this new PAUSE MODE is used. Factory settings are Motor speed 50 Rpm and Softstart 5,0 seconds.?


-- FIRMWARE VERSION: 1.1942-BL1 --
1.1942-BL1		

-- FIRMWARE VERSION: 1.1940-BL1 --	
ADDED:  - FIRMWARE              - 			- Firmware rebuilt to reduce the code size. Texts are moved to own configuration for reuse.Especially good when adding languages. Pictures might have slightly diffrent texts now.  Example.... "Softstart at - Jig speed"  is now JIG MODE - Soft start".
CHANGE: - BOTTOM PAUSE          - 			- Bottom pause can be reduced to 0,3seconds. Earlier 0,5
CHANGE: - DEPTH PAUSE           - 			- Depth pause can be reduced to 0,3 second. Earlier 1,0.
CHANGE: - RP PULSES             - 			- When pressing AUTO button or when motor stops and wheel shall go down, no extra time was added as startdelay. Now RP PULSES are always added (0,8 sec factory)
FIXED:  - BIG FONTS             - 			- Texts for choosing big fonts has changed length so they does not cover eachother which can result in scrap characters in the display.
FIXED:  - MOTOR	                - 			- "Motor stop time" (Factory set 0,7 sec) could be reduced to 0 (OUT) which made the motor to not stop at all. Now 0,1sec is minimum.
FIXED:  - MOTOR	                - 			- Motor did start if  the line were released by holding STOP button pressed. The virtual "stoppoint" did not update.
ADDED:  - WHEEL LOCK            - 			- Has it own settings for motor speed and acceleration. Factory default settings are 50RPM and 5,0 Sec
CHANGE: - MENUES                - 			- Motor Soft start and  Wheel laps in menu E154 is moved to E13 and is only active during hauling up. Factory default values are 5,0sec and 0,3 wheel laps

-- FIRMWARE VERSION: 1.1922 -BL1 
FIX: 	- INFO			- VOLTAGE 		- UPDATED ANALOGUE MEASSUREMENT. THE VOLT READING WAS FLUCTUATING.
FIX: 	- INFO 			- BOOST  		- UPDATED ANALOGUE MEASSUREMENT. THE BOOST READING WAS FLUCTUATING.
FIX: 	- INFO 			- HUMIDITY		- UPDATED ANALOGUE MEASSUREMENT. THE HUMIDITY READING WAS FLUCTUATING.
CHANGE: - FACTORY SETTING 	- COOPERATION    	- Factory default settings for Cooperation is changed from "Both Get help and Help other Ex" to "No coopeartion".

-- FIRMWARE VERSION: 1.1920 -BL1
ADDED:  - MENUES 		- BIG FONTS		- ADDING POSSIBILLITY TO SHOW "FISHING DEPTH",  "JIG LENGTH" AND THE TWO CHOOSEN ANALOGUE BARS IN MAIN DISPLAY TOGETHER WITH THE 100% LINE OUT FONT.
ADDED:  - CPU 			- INFO MENUES 		- CPU revision (Hardware version of the CPU) SHOWN IN INFO MENUE [E62 PPP PPP PP].

-- FIRMWARE VERSION: 1.1916 -BL1 -- 
NEW:    - FIRMWAE 		- BOOT LOADER 		- FIRST FIRMWARE WITH BOOTLOADER THAT MAKES IT POSSIBLE TO SEND/RECEIVE FNEW FIRMWARE BETWEEN MACHINES.
NEW: 	- BOOT LOADER 		- INFO MENU		- Bootloader version is displayed in menu INFO [E62 PPP PPP PP].
NEW: 	- CPU			- INFO MENU 		- The CPU revision (REV) is displayed in menu INFO [E62 PPP PPP PP].
NEW:	- FIRMWARE 		- HEX FILE 		- One HEX file only. No need for separated files for PIC186627 or PIC186722.
CHANGE: - WHEEL SPEED 		- MEASSUREMENT		- WHEEL TIMER IS UPDATED EVERY 0,05 SECONDS INSTEAD OF ONLY WHEN A WHEEL PULS IS DETECTED. THIS HELPS REDUCING THE RPM IN DISPLAY WHEN PULSES STOPS COMING.
CHANGE: - SPEED BRAKE 		- 			- THE NEW WAY TO CALCULATE WHEEL SPEED ABOVE ALSO DEACTIVATES SPEED BRAKE WHEN WHEEL SPEED GETS NORMAL AND REPLACES "SPEED BRAKE TIME". 
FIX: 	- COMMUNICATION 	- 			- UPDATED COMMUNICATION ROUTINE TO PREVENT MASTER FROM LOOSING THE COMMUNICATION. 
CAHNGE: - STARTUP 		- ZERO BUTTON		- EARLIER POSSIBILLITY TO SEE SOM EXTRA INFO DURING STARTUP BY HOLDING ZERO BUTTON IS REMOVED. THE ZERO BUTTON IS NOW INSTEAD USED AT STARTUP TO ENTERING FIRMWARE RECEPTION MODE.
CHANGE: - RESET 		- 			- BOTTOM FISHING IS NOW DEFAULT WHEN CHOOSING "NORWEGIAN" IN THE MULTILANGUAGE SETUP.

-- FIRMWARE VERSION: 1.1912 --

-- FIRMWARE VERSION: 1.1836 --
FIX: - FACTORY VALUES 		- DRAG 			- When DRAG was set to more then 90%, Ex will perform Factory reset because the value added with the basic drag trim value exceeds 100%.
NEW: - RESET 			- LCD 			- Reset menu got an new option that resets Display contrast only.

-- FIRMWARE VERSION: 1.1835 --
FIX: - PAUSE MODE 		- TEXTS 		- The three different chooises for PAUS MODE had wrong texts.It does now affext the function of the machine. But it was difficoult to understand what texts ment. The text were. 
							- 1. "Off" was correct.
							- 2. When display should show "50% Display   + 2 Bars" it shows as "Using up button".
							- 3. When display should show  "At power up" it shows as "100% Display + 0 Bars"

-- FIRMWARE VERSION: 1.1834 --
FIX: - MEMORY 			- USER PROFILES 	- User profiles 2 and PROF menu removed due lack of memory. Profile 1 is accessed by Z button that now shows Reset options.

-- FIRMWARE VERSION: 1.1833 --
NEW - COMMUNICATION 					- First  version with communication built in.

-- FIRMWARE VERSION: 1.1818 --
ADDED: 	- COMMUNICATION 	- PROTOCOL		- The first program with network protocol
FIX: 	- SERIAL NUMBER 	. MEX			- Reads the Serial number of MEX card correct, and displays it with KEX card Serial number under INFO [E62 PPP PPP PP].

-- FIRMWARE VERSION: 1.1735 --
CHANGE - DISPLAY 		- TEXT 			- Adjusting the image for serial number display

-- FIRMWARE VERSION: 1.1732 --
CHANGE: - DRAG 						- Programmet innehåller en enda ändring och det är sänkning av effekten till kopplingen som kunde bli för hög om stort DRAG var satt samtidigt som hjulet dras ut bakvägen. Tidigare misstanke  om att 12 volt skulle vara skadligare för kopplingen än 24 volt stämmer inte. Däremot förbrukar Ex mer ström vid 12 volt än 24 eftersom effekten på maskinen är konstant. Vid programmering så har instruktionen varit att välja "Prereserve EEPROM" för att inte skriva över serienummer,  vilket annars skulle leda till att elektroniken måste till fabrik för grundprogrammering. Detta gäller fortfarande, men vissa utgåvor av Microchips IPE (programmerings programmet) kräver nu dessutom att man i textrutan bredvid  "Prereserve EEPROM" markerat "Enter range" skriver in texten 0-3FF. Om detta behövs märks om fältet lämnas tomt, då det blir rött. Annars är det bara att fortsätta.		

-- FIRMWARE VERSION: 1.1642 --
NEW:	- RP 	 		- PULSE STRENGTH 	- There has been reports about that the clutch might get permanent magnetized in Ex. RP pulses like in the old BJ5000 has been built into the program since the start, but has so far not been activated in factory default settings. When activating RP pulses it has proved to be difficult to find values for good functionality. Therefore, we are now releasing the program / firmware 1.1642 where the RP pulses strength can be reduced in power and also fades out for best influence.  
CHANGE:	- MANUAL 		- 			- INTRODUCING THE [] CHARACTERS INTO MANUAL -  The new manual Revision 6 is a total rewritten manual for A4 paper format and much more detailed compare to the older once, with better index register and now also with alphabetic register. Another major change is that pages lacks page numbers. All pages are instead divided into chapters with the [ ] symbols, which also shows how to press the buttons for reaching the value in the display menu system. An example is [E43] that tells us to press button [E]nter, followed by pressing button 4 for (WHEEL) and then 3 for (COUNTER). Button 1-6 are on buttons under display(Numbers are printed on Overlay). Other buttons in the manual are referred to as [S]top, [U]p, [A]uto, [Z]ero and [P]rog. 

-- FIRMWARE VERSION: 1.1538 -- 2015-09-18
FIX: 	- CODE			-			- THEIF CODE SOMETIMES WAS ERASED BY FACTORY RESET.
FIX:	- CODE 			-			- THEOF CODE TIMEOUT TIMER WAS SPEEDING WAY TOO FAST (REMAINS FROM DEVELOPING). NOW THE TIMER IS 1 HOUR.
FIX:	- JIG LENGTH  		- CATCH REGISTRATION	- SETTING JIG LENGTH TO ZERO MADE THE MACHINE TO DETECT CATCH.
NEW:    - USER PROFILES 	- RESET			- ADDING 2 USER PROFILES THAT CAN BE USED INSTEAD OF FACTORY RESET TO LOAD DEFAULT VALUES.
ADDED:	- USER PROFILES 	- MENU			- ADDING THE "PROF" INTO THE MENUE SYSTEM.
ADDED:  - CATCH DETECTION 	             		- THE CATCH REGISTRATION DISPLAY NOW GETS ADDITIONAL INFO ABOUT WHAT TRIGGERED THE CATCH.
ADDED:  - RESET 		- EXCEPTIONS		- FACTORY RESET NOW CLEARS ALL SETTING WITH EXCEPTION OF LANGUAGE, USER PROFILE, AND THEIF CODE.
ADDED:  - RESET - LCD 		- CONTRAST		- FACTORY RESET DOES NOT AFFECT THE DISPLAY CONTRAST.

-- FIRMWARE VERSION: 1.1520 -- 2015-05-13 
FIX: 	- MOTOR                 - STOP          - SOMETIMES THE MOTOR DID NOT START TO HAUL UP THE FISH WHEN LINE WAS PULLED OUT.
CHANGE: - WHEEL LOCK            - STOP POINT    - ADJUSTED STOP POINT WHEN USING WHEEL LOCK.
FIX:	- CATCH REGISTRATION    - WEIGHT        - IMPROVED, SMOOTHER READING OF MOTOR CURRENT VALUE AND WEIGHT. ALSO NOW BOTH CURRENT AND WEIGHT CAN BE SHOWN.
ADDED:  - EXTRA DRAG            - AT CATCH      - DURING CATCH MODE EXTRA PULLING FORCE (DRAG) CAN BE ADDED. 
ADDED:  - EXTRA DRAG            - AT HAUL UP    - DURING HAUL UP MODE MODE EXTRA PULLING FORCE (DRAG) CAN BE ADDED.
ADDED:  - CATCH REGISTRATION 	- WHEEL PULL OUT- IT'S NOW POSSIBLE TO TRIGG THE CATCH REGISTRATION WHEN WHEEL ROLES OUT FOR A DISTANCE IN ALL FISHING PROGRAMS, NOT ONLY IN SPANISH MACKERELL.

-- FIRMWARE VERSION: 1.1435 --
CHANGE: - DISPLAY 		- RESET                 - The LCD Display needs individual adjustments. Therefore ""Contrast"", ""Brightnes"" and ""Light time"" are removed from Factory reset procedure. Contrast during startup is increased from 0% to 9% and might result in darker display for a few seconds.
CHANGE: - DISPLAY 		- CATCH NOTIFICATION	- As factory default value the ""Showing Catch depth"" is changed from ""Never"" to ""Always"".
CHANGE: - DISPLAY 		- MULTILANGUAGE         - The multilanguage display first time power up now shows Norwegian help text."

-- FIRMWARE VERSION: 1.1434 --
FIX: 	- RP          		- FISHING PROGRAMS	- RP pulses worked only in Normal fishing program. Now avaliable in all program.
FIX: 	- CATCH DOWN  		- RP                - Priority""Catch Down"" gets higher prority then RP pulses. This means that if RP fails, Catch Down will pull up and alert the user, instead of just stopping.
FIX: 	- CATCH DETECTION 	- SPEED BRAKE 		- Improved ""Catch on speed brake"" (emidiately when speed brake signal is activated insted of after speed brake is complete). 
FIX  	- SPEED BRAKE 		- MACKEREL PROGRAM 	- Speed brake now also in Mackerell program."

-- FIRMWARE VERSION: 1.1433 --
FIX:    - DISPLAY      		- TEXT       		- Felvisning av staplarna nu korrigerad.
FIX:    - MOTOR        		- SPEED      		- Motorns varvtal har tidigare felaktigt kunnat sättas till 200Rpm. Nu sänkt till 180 som tänkt. Satt värde ovan 180 generar fel i att motorn kan stanna.
FIX:    - CATCH        		- REGISTRATION		- Napp på låg fart borttagen ur SPANSK MAKRILL fiske.
CHANGE: - WHEEL LOCK   		- WHEEL LAPS 		- The new ""Paus mode"" is improved with higher resolution. Increased from 1 wheel lap, to 1/6 wheel lap.
CHANGE  - WHEEL -      		- MAGNETS    		- Number of magnets on wheel is removed from "Factory reset".
NEW:    - DISPLAY      		- FONT       		- Showing ""LINE OUT"" with big character with 100% gets a second option, 50% of the higth of the display. Using 50% gives space for the two bars, if choosen to show. Also ""Auto symbol"" is shown."
NEW:    - DISPLAY      		- BAR        		- Graphic bars showed not correctly.
NEW:    - MOTOR        		- SPEED      		- Speed of motor could be choosen above 180 (up to 200), but will cause motor stopping. Now maximum is 180.
NEW:    - CATCH        		- REGISTRATION 		- Catch detection on low motor speed is removed from program ""Spanish mackarell"".

-- FIRMWARE VERSION: 1.1407 -- "Följande ändringar görs efter gemensamma beslut på mötet med Bjørnar i Lunde 2013.
CHANGE: - RP      		- CONTROL                   - RP pulses as in BJ5000 program 5.1319 witch means only applying pulses when required(if wheel moves too slow when turning for going out). Pules repeats infinitly untill wheel laps has been pulled out.
CHANGE: - DISPLAY 		- SERIAL NUMBER             - Serial number is vieweble under MANU / MORE and INFO.
CHANGE: - CATCH   		- REGISTRATION              - Catch registration is now avaliable on low motor speed, as a complement for lack of motor ampere when motor is stoped.
CHANGE: - DISPLAY 		- FONT                      - Big character for ""LINE OUT"" is retriggered after any push buttom in LINE OUT display.
CHANGE: - MOTOR   		- SPEED                     - Motor speed is shown under MENU / MORE / INFO.
CHANGE: - WHEEL   		- SPEED                     - Wheel speed above 999 RPM is blocked in Wheel speed display.
CHANGE: - CATCH   		- REGISTRATION     - NOTIFY - Some customers dont want to see the "Catch depth" SO NOW "Showting Catch Depth" is added and can be chosen between... 
CHANGE: - CATCH   		- REGISTRATION              - A. Always show at Catch.
CHANGE: - CATCH   		- REGISTRATION              - B. Never show.
CHANGE: - CATCH   		- REGISTRATION              - C. Show only at surface.

-- FIRMWARE VERSION: 1.1407 --

-- FIRMWARE VERSION: 1.1404 --
NEW:   - MOTOR 			-STOP.P 		- Stop poing added for holding the line still in water when motor is shut of.

-- FIRMWARE VERSION: 1.1314 --
CHANGE: - RP 						- Implementation of reverser polarity pulses (RP) for the clutch
ADDED:  - TEXT 			- INFO 			- Serienummer bild under meny INFO











