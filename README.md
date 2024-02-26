# PiRTO
RTO-Cart porting to Raspberry PI Pico board, with on-screen menu for selecting files.

WARNING! PiRTO was tested on Intellivision PAL consoles, it seems it doesn't still work on NTSC one! i'm working on it and i'll update software asap i'll fix the issue


Assembly notes:
Use only 74lvc245 IC, not LVC ones are not 3,3 tolerant and may damage your Pico.

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
https://forums.atariage.com/topic/346024-intellivision-rto-multicart-new-multicart/
https://forums.atariage.com/topic/360687-pirto-preview-new-rto-multicart-powered-by-raspberry-pico/

![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto0.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto1.jpeg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto2.jpeg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto3.jpeg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto4.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/pirto5.jpg)

