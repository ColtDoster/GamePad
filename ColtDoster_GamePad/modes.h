// will distingush what mode the game is in and what level it is on. EX: mode -1 is an intro screen, and mode 0 will be level 0\

#include "introscreen5_MASK.h"
#include "introscreen5_PIX.h"

#define screenW 320 
#define screenH 240

//curMode  = -1;
boolean initIntro = false;
boolean initLevel1 = false;
boolean initLevel2 = false;
boolean initLevel3 = false;
boolean initLevel4 = false;
boolean initLevel5 = false;
boolean initLevel6 = false;


void introScreen(){
  if(!initIntro){
     tft.setClipRect(0,0, screenW,screenH);
      tft.drawRGBBitmap(0,0,introscreen5_PIX[0],introscreen5_MASK[0],screenW,screenH);
      tft.updateScreen();
  }
  initIntro = true;
  if(buttonBuffer[0] == 1){
    curMode = 0;
  }
}

void firstLevel(){
  initIntro = false;
    if(initLevel1 == false){
    tft.setClipRect(0,0,screenW,screenH);
    drawLevel(0);
    tft.updateScreen();
    initLevel1 = true;
    //enemyStatus = true;
    }
  drawLevel(0);
  statusBar(healthX, healthY, healthW, healthH);
  drawHero();
    if(interaction[curMode][curTile] == 0x01 && buttonBuffer[0] == 1){
    curMode = 1;
    initLevel1 = false;
  } 
}

void secondLevel(){
  //initLevel1= false;
    if(initLevel2 == false){
    tft.setClipRect(0,0,screenW,screenH);
    heroX = 160;
    heroY = 220;
    enemyX = 160;
    enemyY = 120;
    drawLevel(1);
    enemyStatus = true;
    enemyHealth = 3;
    tft.updateScreen();
    initLevel2 = true;
    }
  drawLevel(1);
  statusBar(healthX, healthY, healthW, healthH);
  fight();
  drawEnemy();
  drawHero();
    if(interaction[curMode][curTile] == 0x02 && buttonBuffer[0] == 1){
    curMode = 2;
    initLevel2 = false;
  } 
}

void thirdLevel(){
 // initLevel2= false;
    if(initLevel3 == false){
    tft.setClipRect(0,0,screenW,screenH);
    heroX = 160;
    heroY = 2;
    enemyX = 50;
    enemyY = 120;
    drawLevel(2);
    enemyStatus = true;
    enemyHealth = 3;
    tft.updateScreen();
    initLevel3 = true;
    }
  drawLevel(2);
  statusBar(healthX, healthY, healthW, healthH);
  fight();
  drawEnemy();
  drawHero();
    if(interaction[curMode][curTile] == 0x03 && buttonBuffer[0] == 1){
    curMode = 1;
    initLevel3 = false;
  }  else if(interaction[curMode][curTile] == 0x04 && buttonBuffer[0] == 1){
    curMode = 3;
    initLevel3 = false;
  }
}

void fourthLevel(){
  //initLevel3= false;
    if(initLevel4 == false){
    tft.setClipRect(0,0,screenW,screenH);
    heroX = 300;
    heroY = 120;
    enemyX = 160;
    enemyY = 120;
    drawLevel(3);
    enemyStatus = true;
    enemyHealth = 3;
    tft.updateScreen();
    initLevel4 = true;
    }
  drawLevel(3);
  statusBar(healthX, healthY, healthW, healthH);
  fight();
  drawEnemy();
  drawHero();
    if(interaction[curMode][curTile] == 0x05 && buttonBuffer[0] == 1){
    curMode = 4;
    initLevel4 = false;
  }
}

void fifthLevel(){
  //initLevel4= false;
    if(initLevel5 == false){
    tft.setClipRect(0,0,screenW,screenH);
    heroX = 20;
    heroY = 120;
    enemyX = 270;
    enemyY = 120;
    enemyStatus = true;
    enemyHealth = 3;
    drawLevel(4);
    tft.updateScreen();
    initLevel5 = true;
    }
  drawLevel(4);
  statusBar(healthX, healthY, healthW, healthH);
  fight();
  drawEnemy();
  drawHero();
    if(interaction[curMode][curTile] == 0x07 && buttonBuffer[0] == 1){
    curMode = 5;
    initLevel5 = false;
  }
}
void sixthLevel(){
  //initLevel5= false;
    if(initLevel6 == false){
    tft.setClipRect(0,0,screenW,screenH);
    heroX = 160;
    heroY = 220;
    enemyX = 160;
    enemyY = 120;
    enemyStatus = true;
    enemyHealth = 3;
    drawLevel(5);
    tft.updateScreen();
    initLevel6 = true;
    }
  drawLevel(5);
  statusBar(healthX, healthY, healthW, healthH);
  fight();
  drawEnemy();
  drawHero();
    if(interaction[curMode][curTile] == 0x09 && buttonBuffer[0] == 1){
    curMode = 4;
    initLevel6 = false;
  }
}

void runMode() {

switch(curMode){

 
  case -1: introScreen(); break;
  case 0: firstLevel(); break;
  case 1: secondLevel(); break;
  case 2: thirdLevel(); break;
  case 3: fourthLevel(); break;
  case 4: fifthLevel(); break;
  case 5: sixthLevel(); break;
 
  
}
}
