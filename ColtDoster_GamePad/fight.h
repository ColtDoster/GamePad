

boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = false;           // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}               // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}               // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}               // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}               // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = true;}
  return canMove;
}



void fight(){

  boolean canFight = checkCollide(heroX, heroY, heroSize, heroSize, enemyX, enemyY, enemyW, enemyH);

if(enemyStatus){
  if(canFight){
    if(buttonBuffer[1] == 1){
      enemyHealth -=1;
      if(enemyHealth ==0){
        enemyStatus = false;
        tft.setClipRect(0,0,screenW,screenH); 
        drawLevel(curMode);
        statusDrawn = false;
        statusBar(healthX, healthY, healthW, healthH);
        tft.updateScreen();
      }

    } 

    if(enemyType == 0){
      if(random(100) ==  0){
      punch = true;
      healthX +=5;
      heroHealth -=5;
      healthW -=5;
      tft.setClipRect(0,0,screenW,screenH);
      drawLevel(curMode);
      statusDrawn = false;
      statusBar(healthX, healthY, healthW, healthH);
      tft.updateScreen();
      punch = false;
      }
    }
    else  if(enemyType == 1){
      if(random(100) ==  0){
      punch = true;
      healthX +=10;
      heroHealth -=10;
      healthW -=10;
      tft.setClipRect(0,0,screenW,screenH);
      drawLevel(curMode);
      statusDrawn = false;
      statusBar(healthX, healthY, healthW, healthH);
      tft.updateScreen();
      punch = false;
      }
    }

    
  } 

  }

if(heroHealth < 1){
  death();
  tft.updateScreen();
}
  
}
