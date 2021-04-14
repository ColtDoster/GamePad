#include "AdminThugs_MASK.h"
#include "AdminThugs_PIX.h"

int enemyFrameTime = 250;
int enemyBrainTime = 1000;

Metro enemyFrameTimer = Metro(enemyFrameTime); // A prototype for a Metro timer
Metro enemyBrainTimer = Metro(enemyBrainTime); // A prototype for a Metro timer

//
int enemyMargin = 1; // margin for drawing clip around enemty
int enemyStatus = 1; // keeps track of if enemy is active or not
int enemyType = 0;  // which type of enemy it is
int enemyHealth = 1; // keeps track of health of enemy
int enemySmart = 3; // how smart is the enemy

float enemyX = 0; // x position of the enemy
float enemyY = 0; // the Y position of the enemy
float enemyXDir = 0; // enemy moving left(-1) or right(1)
float enemyYDir = 0; // enemy moving up(-1) or down(1)
float enemySpeed = 0.15; // how fast can the enemy move

int enemyW = 32; //width of sprite
int enemyH = 32; //height of sprite
int enemyFrame = 0; // animaiton frame of the enemy
boolean enemyFire = false; // is the enemy hitting anything

int firstDice; // the first dice roll in the demonstration from class, chooses whether the enemy will be intelligent or not
int secondDice; // chooses whihc random direction the enemy will move

void drawEnemy(){

  float enemyNextX = enemyX + (enemyXDir * enemySpeed);
  float enemyNextY = enemyY + (enemyYDir * enemySpeed);


  if(enemyBrainTimer.check()){
    firstDice = random(0,enemySmart);
    if(firstDice == 0){
     secondDice = random(-1,2);
     enemyXDir = secondDice;
     enemyYDir = secondDice; 
    }  
  } else{
    if(heroX < enemyX){
      enemyXDir = -1;
    } else if (heroY < enemyY){
      enemyYDir = -1;
    } else if(heroX > enemyX){
      enemyXDir = 1;
    } else if (heroY > enemyY){
      enemyYDir = 1;
    }
  }

if(checkMove(curMode, enemyNextX, enemyNextY, enemyW, enemyH) == true){
  enemyX = enemyNextX;
  enemyY = enemyNextY;
}

if(enemyFrameTimer.check()){
  if(enemyXDir == -1 || enemyYDir == -1){enemyFrame = 1 + (enemyFrame + 1) % 3;}
  else if(enemyXDir == 1 || enemyYDir == 1){enemyFrame = 7 + (enemyFrame + 1) % 3;}
  else{enemyFrame = 0; }
}

tft.setClipRect((enemyX - 5), (enemyY - 5), enemyW + 10, enemyH + 10);
drawLevel(curMode);
tft.drawRGBBitmap(enemyX,enemyY,AdminThugs_PIX[enemyFrame],AdminThugs_MASK[enemyFrame],enemyW,enemyH);

tft.updateScreen();
  
}
