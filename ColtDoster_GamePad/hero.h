#include "BerryBoy_MASK.h"
#include "BerryBoy_PIX.h"
//#include "tile.h"

float heroX = 160;
float heroY = 120;
float heroSpeed = 1.0;

 //void setClipRect(int16_t (heroX-10), int16_t (heroY - 10), int16_t 30, int16_t 30); 


void drawHero(){
  heroX += (joyStickBuffer[0] * heroSpeed);
  heroY += (joyStickBuffer[1] * heroSpeed);

  drawLevel(0);

 tft.setClipRect((heroX-10), (heroY - 10), 30, 30);

 tft.drawRGBBitmap(heroX,heroY,BerryBoy_PIX[0],BerryBoy_MASK[0],20,20);


}
