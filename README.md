# PiRTO

RTO-Cart porting to Raspberry PI Pico board, with on-screen menu for selecting files.

WARNING! PiRTO was developed and tested with PAL consoles, but for NTSC you need to use the .NTSC firmware that include longer delays for NTSC console


Assembly notes:
Use only 74lvc245 IC, not LVC ones are not 3,3 tolerant and may damage your Pico.
For SMD pcb version: added 3 jumper, connect 3v3 and Gnd ones, but leave open Shield jumper, connecting to Gnd seems shorting some Pico chinese clones.

Solder the microSD arduino shields on BOTTOM of the board, BEFORE you solder the Pico. Cut the pin to avoid they touche the Pico board on other sides.

Error codes (number of led flashes every second then 2 seconds pause):

1 blinks: Files too big  

2 blinks: Verify BIN files error   

3 blinks: [mapping] not found in CFG error

4 blinks: Card not initialized

5 blinks: Error opening Root

6 blinks: Map CFG error

1 blink every 800 ms is business as usual


More infor on:
https://forums.atariage.com/topic/360687-pirto-preview-new-rto-multicart-powered-by-raspberry-pico/

https://forums.atariage.com/topic/346024-intellivision-rto-multicart-new-multicart/

## Ver. 1.1 Upgrade
New version doesn't use anymore hardcoded delay in bus cycles, so it should work for every Intellivision (NTSC,PAL or SECAM).
I included the uf2 firmware in binaries folder. 
Note: with this version some games with more than 8/9 map pages (i.e. Antartic Tale, Wizard of War, etc.) don't work. Use 1.0 if you have no timing issues.


![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto0.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto1.jpeg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/Pirto6.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/Pirto7.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto4.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto5.jpg)

