# RTO-Cart
RTO-Cart porting to Raspberry PI Pico board, with on-screen menu for selecting files.

Assembly notes:
Use only 74lvc245 IC, not LVC ones are not 3,3 tolerant and may damage your Pico.

Solder the microSD arduino shields on BOTTOM of the board.


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


![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/PiRTO1.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/PiRTO2.jpg)
![ScreenShot](https://raw.githubusercontent.com/aotta/PiRTO/main/pictures/PiRTO3.jpg)

