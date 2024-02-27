/*
//                       PiRTO-CART by Andrea Ottaviani 
// Intellivision multicart based on Raspberry Pico board -

// v. 1.0 2023-12-28 : Initial version for Pi Pico porting of RTO-Cart for Teensy 4.1
//
// Thanks to John Dullea (dwarfaxe@yahoo.com) for his support and his ACC projects, from wich i get some bits of code
// 
//  More info on https://github.com/aotta/RTO-Cart
*/

#define NTSC    // use if you want delays for NTSC machines

#ifdef NTSC
// (270mhz: 134 x PAL, 176 x NTSC) 
#define delWR "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop" 
              
              
// (270mhz: 104 x PAL, 144 x NTSC)
#define delRD "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;"
#else // PAL! 
// (270mhz: 134 x PAL, 176 x NTSC)
#define delWR "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"  
              
// (270mhz: 104 x PAL, 144 x NTSC)
#define delRD "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;" \
              "nop;nop;nop;nop;"
#endif

#include "hardware/gpio.h"
#include "pico/platform.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/divider.h"
#include "hardware/flash.h"
#include "hardware/sync.h"
#include "string.h"
#include "splash.h"
#define splash_size 6144

// include for Spi cards
#include <SPI.h>
#include <SD.h>


// This are GP pins for SPI0 on the Raspberry Pi Pico board, and connect
// to different *board* level pinouts.  Check the PCB while wiring.
// Only certain pins can be used by the SPI hardware, so if you change
// these be sure they are legal or the program will crash.
// See: https://datasheets.raspberrypi.com/picow/PicoW-A4-Pinout.pdf
const int _MISO = 16;//4;  // AKA SPI RX
const int _MOSI = 19;//77;  // AKA SPI TX
const int _CS = 17;//5;
const int _SCK = 18;//6;

// include the SD library:
#include <SPI.h>
#include <SD.h>

// set up variables using the SD utility library functions:
//SdFs sd;
File root;
File entry;
File mapfile;

// Pico pin usage definitions

#define B0_PIN    0
#define B1_PIN    1
#define B2_PIN    2
#define B3_PIN    3
#define B4_PIN    4
#define B5_PIN    5
#define B6_PIN    6
#define B7_PIN    7
#define F0_PIN    8
#define F1_PIN    9
#define F2_PIN    10
#define F3_PIN    11
#define F4_PIN    12
#define F5_PIN    13
#define F6_PIN    14
#define F7_PIN    15
#define MISO_PIN  16
#define CS_PIN    17
#define SCK_PIN   18
#define MOSI_PIN  19
#define RST_PIN 20
#define MSYNC_PIN 21
#define BDIR_PIN  22
#define LED_PIN   25
#define BC1_PIN   26
#define BC2_PIN   27
#define DIR_PIN   28 // TO PIN 1 LVC245, HIGH= A->B (INPUT 5V TO 3.3V) LOW= B->A (OUTPUT 3.3V TO 5V)

int D_PIN[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};


// Pico pin usage masks

#define B0_PIN_MASK     0x00000001L
#define B1_PIN_MASK     0x00000002L
#define B2_PIN_MASK     0x00000004L
#define B3_PIN_MASK     0x00000008L
#define B4_PIN_MASK     0x00000010L
#define B5_PIN_MASK     0x00000020L
#define B6_PIN_MASK     0x00000040L
#define B7_PIN_MASK     0x00000080L

#define F0_PIN_MASK     0x00000100L
#define F1_PIN_MASK     0x00000200L
#define F2_PIN_MASK     0x00000400L
#define F3_PIN_MASK     0x00000800L
#define F4_PIN_MASK     0x00001000L
#define F5_PIN_MASK     0x00002000L
#define F6_PIN_MASK     0x00004000L
#define F7_PIN_MASK     0x00008000L

#define MISO_PIN_MASK   0x00010000L
#define CS_PIN_MASK     0x00020000L
#define SCK_PIN_MASK    0x00040000L
#define MOSI_PIN_MASK   0x00080000L
#define RST_PIN_MASK    0x00100000L
#define MSYNC_PIN_MASK  0x00200000L
#define BDIR_PIN_MASK   0x00400000L
#define LED_PIN_MASK    0x02000000L
#define BC1_PIN_MASK    0x04000000L
#define BC2_PIN_MASK    0x08000000L
#define DIR_PIN_MASK    0x10000000L

// Aggregate Pico pin usage masks

#define BX_PIN_MASK     0x000000FFL
#define FX_PIN_MASK     0x0000FF00L
#define DATA_PIN_MASK   0x0000FFFFL
#define BUS_STATE_MASK  0x0C400000L
#define ALWAYS_IN_MASK  (BUS_STATE_MASK)
#define ALWAYS_OUT_MASK (LED_PIN_MASK)

// Inty bus values (BC2+BC1+BDIR)
// RTO Inty bus values (BDIR+BC1+BC2) ??  1 2 3 -> 2 3 1

#define BUS_NACT  0b000  //0
#define BUS_ADAR  0b010  //2
#define BUS_IAB   0b100  //4
#define BUS_DTB   0b110  //6
#define BUS_BAR   0b001  //1
#define BUS_DW    0b011  //3
#define BUS_DWS   0b101  //5
#define BUS_INTAK 0b111  //7

unsigned char busLookup[8];

// We're going to erase and reprogram a region 256k from the start of flash.
// Once done, we can access this at XIP_BASE + 256k.


char RBLo,RBHi;
#define BINLENGTH  100000L
#define RAMSIZE  0x2000
uint16_t ROM1[BINLENGTH];
uint16_t RAM[RAMSIZE];
#define maxHacks 32
uint16_t HACK[maxHacks];
uint16_t HACK_CODE[maxHacks];


unsigned int parallelBus2;
  
unsigned int romLen;
unsigned int ramfrom = 0;
unsigned int ramto =   0;
unsigned int mapfrom[80];
unsigned int mapto[80];
unsigned int maprom[80];
unsigned int addrto[80];
unsigned int RAMused = 0;

unsigned int tipo[80];  // 0-rom / 1-page / 2-ram
unsigned int page[80];  // page number
int slot;
int hacks;

uint32_t selectedfile_size;    // BIN file size
char longfilename[60];         // long file name (trunked) 
char mapfilename[60];          // map cfg file name
char testfilename[60];         // for check if directory
char rewindfilename[60];       // for rewind browsing
char rewindprev[60];       // for rewind browsing
int lenfilename; 
char path[60];
char path1[60];
char tiposcelta[9];
bool pressed=false;



////////////////////////////////////////////////////////////////////////////////////
//                     Error(N)
////////////////////////////////////////////////////////////////////////////////////
void error(int numblink){
  while(1){
    for(int i=0;i<numblink;i++) {
      digitalWrite(LED_BUILTIN,HIGH);
      delay(600);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
    }
  delay(2000);
  }
}

////////////////////////////////////////////////////////////////////////////////////
//                     REBOOT
////////////////////////////////////////////////////////////////////////////////////

void doReboot() {
  rp2040.reboot();
}

////////////////////////////////////////////////////////////////////////////////////
//                     RESET
////////////////////////////////////////////////////////////////////////////////////
void resetCart() {
  
  digitalWrite(RST_PIN,HIGH);
  delay(30);  // was 20 for Model II; 30 works for both
  digitalWrite(RST_PIN,LOW);
  delay(3);  // was 2 for Model II; 3 works for both
  while (digitalReadFast(MSYNC_PIN)==1);
  delay(1);  // was 1 for Model II
  digitalWrite(RST_PIN,HIGH);
}

////////////////////////////////////////////////////////////////////////////////////
//                     HANDLE BUS
////////////////////////////////////////////////////////////////////////////////////

void __time_critical_func(loop1()) {   //HandleBUS()
  unsigned int lastBusState, busState1;
  unsigned int busSt1, busSt2;
  unsigned int parallelBus;
  unsigned int dataOut, dataInd;
  unsigned int dataWrite=0;
  unsigned char busBit;
  bool deviceAddress = false; 
  //unsigned int delRD=482;
  //unsigned int delWR=540;
  //unsigned int delADAR=0;
  unsigned int curPage=0;
  unsigned int checkPage=0;
  int exitBUS;
   
  busState1 = BUS_NACT;
  lastBusState = BUS_NACT;
  
  dataOut=0;

  // Main loop   

 for (int i = 0; i <= 16; i++)
  {
    gpio_init(i);  
  }
  
  gpio_init(DIR_PIN);
  gpio_init(BDIR_PIN);
  gpio_init(BC1_PIN);
  gpio_init(BC2_PIN);
  gpio_init_mask(ALWAYS_IN_MASK);
  gpio_init_mask(ALWAYS_OUT_MASK);
  
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(28,OUTPUT);
  
  gpio_set_dir_in_masked(DATA_PIN_MASK);
  gpio_set_dir_in_masked(ALWAYS_IN_MASK);
  gpio_set_dir_out_masked(ALWAYS_OUT_MASK);
 
  // Initial conditions
  
  gpio_clr_mask(DIR_PIN_MASK);

  exitBUS=1;
  
  gpio_clr_mask(DIR_PIN_MASK | DATA_PIN_MASK);
  gpio_set_dir_in_masked(DATA_PIN_MASK); // Set to input


  Serial.println("Entering main loop");
  
  while (exitBUS)
  {

  
    // Wait for the bus state to change
  
    do {
    } while (!((gpio_get_all() ^ lastBusState) & BUS_STATE_MASK));
    // We detected a change, but reread the bus state to make sure that all three pins have settled
     lastBusState = gpio_get_all();

    // busState1 = (((lastBusState >> BDIR_PIN) & 1) + ((lastBusState >> BC1_PIN) & 3)); //if gpio9    
    busSt1=((lastBusState >> BDIR_PIN) & 1);
    busSt2=((lastBusState >> BC1_PIN) & 3)*2;
    busState1=busSt1+busSt2;
    
   
    busBit = busLookup[busState1];
    // Avoiding switch statements here because timing is critical and needs to be deterministic
    if (!busBit)
    {
      // -----------------------
      // DTB
      // -----------------------
      // DTB needs to come first since its timing is critical.  The CP-1600 expects data to be
      // placed on the bus early in the bus cycle (i.e. we need to get data on the bus quickly!)
 
      if (deviceAddress)
      {
       
        // The data was prefetched during BAR/ADAR.  There isn't nearly enough time to fetch it here.
        // We can just output it.
      // Wait of 482ns 
        //delayNanoseconds(delWR);   // to tune ok a 360 / 380
        gpio_set_dir_out_masked(DATA_PIN_MASK);
        gpio_put_masked(DATA_PIN_MASK,dataOut);
        asm inline ("nop;nop;nop;nop;");
        gpio_clr_mask(DIR_PIN_MASK);
    
        asm inline (delWR); //150ns
              
        gpio_set_dir_in_masked(DATA_PIN_MASK);
        gpio_set_mask(DIR_PIN_MASK);
      }
     }
    else
    {
      busBit >>= 1;
      if (!busBit)
      {
        // -----------------------
        // BAR, ADAR
        // -----------------------
       if ((deviceAddress) and (busState1==BUS_ADAR)) 
      {
        // The data was prefetched during BAR/ADAR.  There isn't nearly enough time to fetch it here.
        // We can just output it.
                
        gpio_set_dir_out_masked(DATA_PIN_MASK); // to set pins to outputs (bit0-15)
        gpio_put_masked(DATA_PIN_MASK,dataOut);
        gpio_clr_mask(DIR_PIN_MASK); //set bus dir to output
        
        asm inline (delWR); //150ns
        
       gpio_set_dir_in_masked(DATA_PIN_MASK);
       gpio_set_mask(DIR_PIN_MASK);
      }
      /// ELSE is BAR
        // Prefetch data here because there won't be enough time to get it during DTB.
        // However, we can't take forever because of all the time we had to wait for
        // the address to appear on the bus.
        gpio_set_dir_in_masked(DATA_PIN_MASK);  // to set pins to inputs (bit 0-15)
        gpio_set_mask(DIR_PIN_MASK); //set bus dir to input   
       // We have to wait until the address is stable on the bus
       // delayNanoseconds(delRD-delADAR); // waiting bus is stable 66 nop at 200mhz is ok/85 at 240
   
       asm inline (delRD); //150ns
          
       parallelBus = gpio_get_all() & 0xFFFF; 
     
       parallelBus2=parallelBus;
       // Load data for DTB here to save time
       
        deviceAddress = false;
        
          for (int i=0; i < slot+1; i++) {
            if ((parallelBus >= maprom[i]) && (parallelBus<=addrto[i])) {
              if (tipo[i]==0) {
                dataOut=ROM1[(parallelBus - maprom[i]) + mapfrom[i]];
                deviceAddress = true;
                break;
              }
              if (tipo[i]==1) {
                if ((parallelBus & 0xfff)==0xfff) {
                  checkPage=1;
                 // Serial.println("ck"); // test to remove
                  deviceAddress = true;
                  break;
                }
                if (page[i]==curPage) {
                  dataOut=ROM1[(parallelBus - maprom[i]) + mapfrom[i]];
                  deviceAddress = true;
                  break;
                }
              }
              if (tipo[i]==2) {
                dataOut=RAM[parallelBus - ramfrom];
                deviceAddress = true;
                break;
              }
              
            }    
          }
   
  
        if (hacks>0) {
          for (int i=0; i<maxHacks;i++) {
            if (parallelBus==HACK[i]) {
              dataOut=HACK_CODE[i];
              deviceAddress = true;
            }
            break;
          }
        } 
      }
      else
      {
         busBit >>= 1;
        if (!busBit)
        {
          // -----------------------
          // DWS
          // -----------------------
          
          if (deviceAddress) {

            gpio_set_dir_in_masked(DATA_PIN_MASK);  // to set pins to inputs (bit 0-15)
            gpio_set_mask(DIR_PIN_MASK); //set bus dir to input   
    
           
            dataWrite = gpio_get_all() & 0xFFFF; 
          
           
           if (RAMused == 1) {
             RAM[parallelBus-ramfrom]=dataWrite;
           } 
           if ((checkPage == 1) && (((dataWrite >> 4) & 0xff) == 0xA5)) {
              curPage=dataWrite & 0xf;
             // Serial.println(curPage); // Poi via!!!!!!!!!!!!!!!!!!!
              checkPage=0;
           }
           
        }
        else
        {
         // -----------------------
         // NACT, IAB, DW, INTAK
         // -----------------------
         // reconnect to bus
           
           gpio_set_dir_in_masked(DATA_PIN_MASK);  // to set pins to inputs (bit 0-15)
           gpio_set_mask(DIR_PIN_MASK); //set bus dir to input   
    
        }
        
        }
      } 
    }    
  }
} 


////////////////////////////////////////////////////////////////////////////////////
//                     LOAD ROM
////////////////////////////////////////////////////////////////////////////////////

void loadROM() {

  
  String riga;
  char tmphex[] {0,0,0,0,0,0};
   uint8_t file_buffer[FLASH_PAGE_SIZE];
  int linepos;
  int page_counter;
  int numErr=0;
  
  strcat(path,"/");
  memcpy(path1,path,strlen(path)+1);
  Serial.print("path:");Serial.println(path);
 
  for(int i=0; i<55; i++) {
        if (longfilename[i]=='.') {
          lenfilename= i;  //dot found
        }
  }
  memcpy(mapfilename,longfilename,lenfilename);
  strcat(path1,longfilename);
  
  Serial.print("opening:");Serial.println(path1); 
  entry=SD.open(path1,FILE_READ);
  if (!entry) Serial.print("File not found:");Serial.println(path1);

  strcat(mapfilename,".cfg");
  
  strcat(path,mapfilename);
  
  mapfile=SD.open(path,FILE_READ);
  Serial.print("Map:");Serial.println(path);
  
  if (!mapfile) {
    mapfile.openNextFile();
    mapfile=SD.open("0.cfg",FILE_READ);
    Serial.println("using 0.cfg");
    }
  if (!mapfile) {
    Serial.print("Map CFG file error");
    error(6); // 6 error Map CFG
  }

  slot=0;
  hacks=0;
  RAMused=0;
  
  while (mapfile.available()) {
    riga=mapfile.readStringUntil('\n');
    Serial.println(riga);
    if (riga.length()>1) {
      String tmp=riga.substring(0,9);
      if (slot==0) {
        if (tmp=="[mapping]") {
          riga=mapfile.readStringUntil('\n');
        } else {
          Serial.print("[mapping] not found");
          error(3); // 3 error [mapping] section not found
        }
      }
    
      if (tmp=="[memattr]") {
        riga=mapfile.readStringUntil('\n');
        tmp=riga.substring(1,5);
        tmp.toCharArray(tmphex,5);
        ramfrom=strtoul(tmphex,NULL,16);
        mapfrom[slot]=ramfrom;
        tmp=riga.substring(9,13);
        tmp.toCharArray(tmphex,5);
        ramto=strtoul(tmphex,NULL,16);
        mapto[slot]=ramto;
        maprom[slot]=ramfrom;
        addrto[slot]=maprom[slot]+(mapto[slot]-mapfrom[slot]);
        tipo[slot]=2; // RAM
        RAMused=1;
        slot++;
    
      } else {
        tmp=riga.substring(0,1);
        if (tmp=="p") {
          // [MACRO]
          tmp=riga.substring(2,6);
          tmp.toCharArray(tmphex,6);
          HACK[hacks]=strtoul(tmphex,NULL,16);
          tmp=riga.substring(7,10);
       
          tmp.toCharArray(tmphex,4);
          HACK_CODE[hacks]=strtoul(tmphex,NULL,16);
          Serial.print(HACK[hacks],HEX);Serial.print("-");
          Serial.println(HACK_CODE[hacks],HEX);
          hacks++;
         
        } else {
        //mapping
        linepos=riga.indexOf("-");
        if (linepos>=0) {
          tmp=riga.substring(1,linepos-1);
          tmp.toCharArray(tmphex,6);
          mapfrom[slot]=strtoul(tmphex,NULL,16);
          tmp=riga.substring(linepos+3,linepos+9);
          tmp.toCharArray(tmphex,6);
          mapto[slot]=strtoul(tmphex,NULL,16);
          if (linepos==6) {
            tmp=riga.substring(linepos+11,linepos+15);
          } else {
            tmp=riga.substring(linepos+12,linepos+17);
          }
          tmp.toCharArray(tmphex,6);
          maprom[slot]=strtoul(tmphex,NULL,16);
          if (linepos==6) {
            tmp=riga.substring(22,26);
          } else {
            tmp=riga.substring(24,28);
          }  
          tmp.toCharArray(tmphex,6);
          addrto[slot]=maprom[slot]+(mapto[slot]-mapfrom[slot]);
          if (!(strcmp(tmphex,"PAGE"))) {
            tipo[slot]=1;
            if (linepos==6) {
              tmp=riga.substring(27,28);
            } else {
              tmp=riga.substring(29,31);
            }   
          tmp.toCharArray(tmphex,2);
          page[slot]=strtoul(tmphex,NULL,16);
          } else {
            tipo[slot]=0;
          }
          slot++;
          }
        }
        Serial.print("Slot:");Serial.print(slot-1);
        Serial.print("-From:");Serial.print(mapfrom[slot-1],HEX);
        Serial.print(" to:");Serial.print(mapto[slot-1],HEX);
        Serial.print(" IN:");Serial.print(maprom[slot-1],HEX);
        Serial.print(" tipo:");Serial.print(tipo[slot-1]);
        Serial.print(" page:");Serial.print(page[slot-1]);
        Serial.print(" addr-to:");Serial.println(addrto[slot-1],HEX);
        }
     }
  }
  
  RAM[0x1111]=1;
  RAM[0x651]=0;
  delay(50);
  if (hacks>0) {
    Serial.println("HACKs Found!");
  }

  slot--;  // conservo il numero di slot!

  Serial.print("Slots:");Serial.println(slot);
  
  if (entry) {
    // read from the file until there's nothing else in it:
    romLen=0;
    while (entry.available()) {
      RBHi = entry.read();
      RBLo = entry.read();
      unsigned int dataW= RBLo | (RBHi << 8);
      ROM1[romLen]=dataW;
      romLen++;
         if (romLen>BINLENGTH) {
       Serial.println("File too big!");
          error(1); // 1 file too big
          while(1);
      }
    }
   Serial.print("Rom lenght:");Serial.println(romLen,HEX);
  //verify
  //  slot=0;
    romLen=0;
    entry.seek(0);
    while (entry.available()) {
      RBHi=entry.read();
      RBLo=entry.read();
      unsigned int dataW= RBLo | (RBHi << 8);
      //fileOffset=romLen - mapfrom[slot] + maprom[slot];
      if (ROM1[romLen]!= dataW) {
        Serial.print("@:");Serial.print(romLen,HEX);Serial.print("-");
        Serial.print(ROM1[romLen],HEX);Serial.print("-");Serial.println(dataW,HEX);
        numErr++;
      } 
      romLen++;
     } 
     Serial.print("Rom lenght:");Serial.println(romLen,HEX);
    // close the file:
    entry.close();
  } else {
    // if the file didn't open, print an error:
          Serial.print("Verify error 2");
          error(2);
  return; 
  Serial.print("Rom lenght:");Serial.println(romLen-1);
  }
  if (numErr!=0) {
    Serial.print("Verify error n. ");Serial.println(numErr);
    error(2); // 2 error Verify rom 
  } else {
    Serial.println("Verify OK");
  }
}


////////////////////////////////////////////////////////////////////////////////////
//                     MENU INTELLIVISION
////////////////////////////////////////////////////////////////////////////////////    
#pragma GCC push_options
#pragma GCC optimize ("O0")

void __time_critical_func(IntyMenu()) {
  int i; 
  int rootpos[255];
  char menu[600];
  int lastpos;
  char suf[10];                 // extension file 
  uint64_t file_size;        // tailles des fichiers affiches
  // Initialisations
  selectedfile_size = 0;          // initialisation de la taille du fichier choisi
  file_size = 0;
  bool filefound = false;
  bool selected = false;
  int subfolder = 0;    // nexting subfolders counter
  int dot = 0;
  int numrighe=10;
  int numcurriga=0;
  int contfile=0;
  int choose=0;
  bool sdInitialized = false;
  bool rewind=false;
  bool finelista=false;
  // Ensure the SPI pinout the SD card is connected to is configured properly
  // Select the correct SPI based on _MISO pin for the RP2040
  sdInitialized = SD.begin(_CS);
  if (!sdInitialized) {
      Serial.println("initialization failed.");
      error(4); // 4 error Card not init
      while(1); 
  }  
  // Boucle de choix du fichier
  path[0]=0;path1[0]=0;
  if (!(root=SD.open("/"))) {
    Serial.println("Error opening Root");
     error(5); // 5 error Root CFG
  while(1);
  }

  for(int i=0;i<(splash_size/2);i++){
    unsigned int dataW= _acpirto[(i*2)+1] | (_acpirto[i*2] << 8);
    ROM1[i]=dataW;
  }

  slot=1; // 2 slot per splash

  //  [mapping]
  //$0000 - $0BFF = $5000

  mapfrom[0]=0x0;
  mapto[0]=0xbff;
  maprom[0]=0x5000;
  tipo[0]=0;
  page[0]=0;
  addrto[0]=0x5bff;
 //[memattr]
 //$8000 - $9FFF = RAM 16
  RAMused=1;
  ramfrom=0x8000;
  mapfrom[1]=0x8000;
  mapto[1]=0x9fff;
  maprom[1]=0x8000;
  tipo[1]=2;
  page[1]=0;
  addrto[1]=0x9fff;

 
  digitalWrite(LED_BUILTIN,HIGH);
  delay(200);
  resetCart();
  delay(200);
  resetCart();
  Serial.println("Resetted");
 
  digitalWrite(LED_BUILTIN,LOW);

  int c=0;
  pressed=false;
  while((!(pressed))&&(c<=20)) {
  delay(100);
  if (RAM[0x13f]==1) pressed=true;
  RAM[0]=RAM[0x13f];
  c++;
  }
  RAM[0x15F]=123;
  //Serial.println("Choose file!");

  while (!selected) {
    while (numcurriga<=(numrighe-1)) {

      while (!filefound) 
      {
        entry=root.openNextFile();
        //Serial.println(entry.name());
        if(!entry) {
          //Serial.println("!-entry");
          for (int k=numcurriga;k<=(numrighe-1);k++) {
            for(int i=0;i<60;i++){
              menu[k*60+i]=0;
              int poke=(0x17f+i*2)+(k*40);
              if (i<=20) RAM[poke]=0;
            }
          }
          numcurriga=numrighe;
          finelista=true;
          //Serial.println("Exit entry");
          break;
        }
         // quindi c'è un file...
       // Serial.print(entry.name());
       // Serial.println(sizeof(entry.name()));
        if (sizeof(entry.name())>56) {
              Serial.print("Skipping longfilename");
              Serial.println(entry.name());
              continue;
        }
    
        finelista=false;
        memset(longfilename,0,60); 
        String(entry.name()).toCharArray(longfilename,60);
   
        if(entry.isDirectory()) {   //handling subdirectory
            if (strcmp(longfilename,"System Volume Information")==0) {
              memset(longfilename,0,60); 
              for(int i=0;i<20;i++){
                int poke=(0x17f+i*2)+(numcurriga*40);
                RAM[poke]=longfilename[i];
                }
              filefound=false;
            //  Serial.println("Skipping sys vol info");
              continue;
          } else {
            String(entry.name()).toCharArray(longfilename,60);
            filefound=true;
            break; 
          } 
        } 

         dot=0;
        for(i=0; i<57; i++) {
          if (longfilename[i]=='.') {
            dot=i;
          }
        }    
        if(dot==0) 
        {
         for(i=0; i<60; i++) longfilename[i]=0; 
        continue; //dot not found, get next file
        }
        suf[0]=0;
        //test du suffixe
        suf[0]=longfilename[dot+1];
        suf[1]=longfilename[dot+2];
        suf[2]=longfilename[dot+3];
        suf[ 3]=0;
    
        if(strcmp(suf,"bin")!=0  && strcmp(suf,"BIN")!=0 )
          continue; //not BIN file
          filefound=true;     
      }
      // .bin found
      // save position
        if (entry) {
         
        file_size = entry.size();
        int kb=(file_size >>10);
        //Serial.print(longfilename);
        if (entry.isDirectory()) {
        //  Serial.print("DIR-");
            tiposcelta[numcurriga]=2;
            filefound=true;
        }  else {
            tiposcelta[numcurriga]=1;
        }
        

        selectedfile_size=file_size;

      //Serial.println(longfilename);
      for(int i=0;i<60;i++){
           menu[numcurriga*60+i]=longfilename[i];
      }
      // scrive menu in memoria per intellivision
      for(int i=0;i<20;i++){
         int poke=(0x17f+i*2)+(numcurriga*40);
         RAM[poke]=longfilename[i];     
         if (entry.isDirectory()) RAM[poke]=RAM[poke]+0x100;
      }
       
      numcurriga++;
      filefound=false;
      for(i=0; i<60; i++) longfilename[i]=0;
      } 
      Serial.print("-");
    } 
      Serial.print("+");
       
 
    Serial.println("wait key");
    RAM[0x119]=0; RAM[0x651]=0;
    pressed=false;

    int a=0;
    while(!pressed) {
      a=RAM[0x889];
      //a=a+RAM[0x889];
      if (a>=1) pressed=true;
      //if (a!=0)  Serial.print(RAM[0x889]);
    } 
    
    Serial.print("J:");Serial.println(a);
    RAM[0x119]=1;
    delay(20);
    switch (a) {
      case 2:
        if (!finelista) numcurriga=0; // non va avanti se fine lista
        memset(menu,0,sizeof(menu));
        RAM[0x119]=1;  // for inty:reloop in new subfolder
        RAM[0x889]=0;  // reset key        
      break;
      case 8: 
        Serial.print("Rewind");
        RAM[0x119]=1;  // for inty:reloop in new subfolder
        RAM[0x889]=0;  // reset key
        root.rewindDirectory();
        memset(testfilename,0,60);
        contfile=0;
        numcurriga=0;
        //*/
      break;
      case 13:
        Serial.println("Enter");
        RAM[0x119]=0;  // for inty:reloop in new subfolder
        choose=RAM[0x899];
        delay(30);
        while(choose==0) {
            choose=RAM[0x899];
          if (RAM[0x899]!=0) Serial.println(choose);
        }
        RAM[0x119]=1;  // for inty:reloop in new subfolder
        RAM[0x889]=0;  // reset key
        choose--;
        Serial.print("riga:");Serial.println(choose);
        for(int i=0;i<60;i++){
          longfilename[i]=menu[choose*60+i];
          if (longfilename[i]>256) longfilename[i]=longfilename[i]-0x100;
        }
        if (strlen(longfilename)==0) break;
        memset(menu,0,sizeof(menu));
        Serial.print("Scelto:");Serial.println(longfilename);
        entry.close();
        Serial.print("Tipo:");Serial.println(tiposcelta[choose]);
       
        if (tiposcelta[choose]==2) { // open dir
          Serial.println("Open Dir");
          root=SD.open(longfilename);
          root.rewindDirectory();
          Serial.print("Open dir:");Serial.println(longfilename);
          if (!root) Serial.println("error in opening Directory");
          memset(path,0,sizeof(path));
          strcat(path,longfilename);
          Serial.print("New path:");Serial.println(path);
          subfolder++;
          memset(rewindfilename,0,60);       // for rewind browsing
          numcurriga=0;
          pressed=false;
          selected=false;
          delay(140);
           } else {  // open file
           Serial.println("Open File");
           selected=true;
           delay(140);
          }
          delay(250);
        break;
        case 99:
          Serial.println("Root");
          root=SD.open("/");
          memset(path,0,sizeof(path));
          memset(menu,0,sizeof(menu));
          RAM[0x119]=1;  // for inty:reloop in new subfolder
          RAM[0x889]=0;  // reset key
          numcurriga=0;
          subfolder=0;
        break;
      }  //end switch
      memset(menu,0,sizeof(menu));
      RAM[0x889]=0;
      RAM[0x119]=0;
      RAM[0x15f]=0;
      
      //Serial.print("Chose2:");Serial.println(choose);
    }
  }
#pragma GCC pop_options



////////////////////////////////////////////////////////////////////////////////////
//                     SETUP
////////////////////////////////////////////////////////////////////////////////////

void __time_critical_func(setup()) {

 // Well I'll be...while the Pi Pico can run up to 133MHz its default speed
  // on startup is only 125MHz. You have to explicitly set the speed for the
  // higher value.  This affects the number of NOPs that core 1 must use for
  // bus timing, by the way.

  // We need to overclock to 170MHz to accommodate many emulated instructions.
  // It turns out that the reason for the stated maximum speed of the Pico is
  // the flash chip, which only supports up to 133MHz.  We can't run from
  // flash anyway since timing is so critical and we run everything from RAM
  // (flash incurs loading latency that prevents us from keeping up with the
  // Intellivision bus).
  //
 
  set_sys_clock_khz(270000, true); // settled in compiler IDE as 250mhz overclocked

 // Initialize the bus state variables

  busLookup[BUS_NACT]  = 4; // 100
  busLookup[BUS_BAR]   = 1; // 001
  busLookup[BUS_IAB]   = 4; // 100
  busLookup[BUS_DWS]   = 2; // 010   // test without dws handling
  busLookup[BUS_ADAR]  = 1; // 001
  busLookup[BUS_DW]    = 4; // 100
  busLookup[BUS_DTB]   = 0; // 000
  busLookup[BUS_INTAK] = 4; // 100
  
  Serial.begin();
 // while(!Serial);
  Serial.println("P-ON your Inty!");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  pinMode(RST_PIN,OUTPUT);
  pinMode(MSYNC_PIN,INPUT_PULLDOWN);
  digitalWrite(RST_PIN,LOW);
  delay(1000);
  //digitalWrite(RST_PIN,HIGH);
  while (digitalRead(MSYNC_PIN)==0); // wait for Inty powerup
  Serial.println("Inty Pow-ON");

  for (long i=0; i<BINLENGTH; i++) {
    ROM1[i]=0;
  }
 

 for (long i=0; i<RAMSIZE; i++) {
    RAM[i]=0;
  }

 for (int i=0; i<maxHacks; i++) {
  HACK[i]=0;
  HACK_CODE[i]=0;
 }
  IntyMenu();

  loadROM();
  
  RAM[RAMSIZE-1]=222; // for test
  
  delay(200);
  resetCart();
  delay(200);
  resetCart();
   
}
////////////////////////////////////////////////////////////////////////////////////
//                     MAIN LOOP
////////////////////////////////////////////////////////////////////////////////////    
  
void loop() 

{
  int i=0;
  
  // Initialize GPIO pins
  while (i<=40) {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(800);
  Serial.print("."); //parallelBus2,HEX);Serial.print("-");
  digitalWrite(LED_BUILTIN,LOW);
  delay(800);
  i++;
  }
  Serial.println("");i=0;
 }

////////////////////////////////////////////////////////////////////////////////////
//                     MAIN LOOP
////////////////////////////////////////////////////////////////////////////////////    
  
void setup1()
{
  delay(80);

 
}
