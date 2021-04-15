#include "BerryBoy_MASK.h"
#include "BerryBoy_PIX.h"
//#include "tile.h"

#define tileW 16         // 16 Tiles Across
#define tileH 12         // 12 Tiles Down
#define tileSize 20      // Tile Width (in pixels)


float heroX = 160;
float heroY = 120;
float heroSpeed = 0.5;
int heroSize = 32;
int heroDir = 0;
int heroFrame = 0;
int heroTime = 250;

int healthX = 250;
int healthY = 15;
int healthW = 60;
int healthH = 8;

Metro heroFrameTimer = Metro(heroTime); // A prototype for a Metro timer


void drawHero(){

float nextX = heroX +(float(joyStickBuffer[0]) * heroSpeed); 
float nextY = heroY +(float(joyStickBuffer[1]) * heroSpeed); 

if(checkMove(curMode, nextX, nextY, heroSize, heroSize) == true){
  heroX = nextX;
  heroY = nextY;
}

   if(joyStickBuffer[0] < 0 || joyStickBuffer[1] < 0 ){
    heroDir = -1;
  } else if(joyStickBuffer[0] > 0 || joyStickBuffer[1] > 0){
    heroDir = 1;
  } else{
    heroDir = 0;
  }


if(heroFrameTimer.check()){
  if(heroDir == -1){heroFrame = 1 + (heroFrame + 1) % 3;}
  else if(heroDir == 1){heroFrame = 6 + (heroFrame + 1) % 3;}
  else{heroFrame = 0; }
}

if(heroDir == 1 && buttonBuffer[1] == 1){
  heroFrame = 9;
} else if(heroDir == -1 && buttonBuffer[1] == 1){
  heroFrame = 4;
} else if(heroDir == 0 && buttonBuffer[1] ==1){
  heroFrame = 4;
}



 tft.setClipRect((heroX-5), (heroY - 5), 45, 45);

 tft.drawRGBBitmap(heroX,heroY,BerryBoy_PIX[heroFrame],BerryBoy_MASK[heroFrame],heroSize,heroSize);

//tft.setClipRect(healthX, healthY, healthW, healthH); 
// statusBar(healthX, healthY, healthW, healthH);

tft.updateScreen();


}
