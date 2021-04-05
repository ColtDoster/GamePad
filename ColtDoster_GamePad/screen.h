
#include <ILI9341_t3n.h>
#include <Metro.h> // This adds the Metro library to your sketch


#include <SPI.h>

#define TFT_DC  9
#define TFT_CS  10
#define TFT_RST 8    

ILI9341_t3n tft = ILI9341_t3n(TFT_CS, TFT_DC, TFT_RST);

#define screenW 320 
#define screenH 240 
DMAMEM uint16_t screenBuffer[screenW * screenH];    // screen buffer

//colors
//#define BLACK    0x0000
//#define WHITE    0xFFFF
boolean color;

//timer variables
int screenTime1 = 2000;

Metro screenTimer1 = Metro(screenTime1); // A prototype for a Metro timer



void initScreen(){  //INITIALOZES THE SCREEN
 tft.begin();                            // Connect to LCD Screen
  tft.setRotation(1);                   // Rotate Screen 90 Degrees
  
  tft.setFrameBuffer(screenBuffer);   // Initialize Frame Buffer
  tft.useFrameBuffer(1);                // Use Frame Buffer

  tft.fillScreen(ILI9341_BLACK);      // Clear Screen

  color = false;  // set to false so that way screen comes in black
}

void screenTest(){

  if(screenTimer1.check()){
    color = !color;
  }

if(color){
  tft.fillScreen(ILI9341_WHITE); // Clear Screen
  tft.updateScreen();
}else{
  tft.fillScreen(ILI9341_BLACK); // Clear Screen
  tft.updateScreen();
}




}
