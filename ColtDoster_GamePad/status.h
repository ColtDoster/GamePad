
boolean statusDrawn = false;

void statusBar(int statusX, int statusY, int statusW, int statusH){

  if(statusDrawn == false){
  tft.drawRect(statusX, statusY, statusW, statusH, 0xFFFFFF);
  tft.fillRect(statusX+1, statusY+1, statusW-1, statusH-1, 0x0000FF);
  tft.updateScreen();
  } 

  statusDrawn = true;
}


void death(){
tft.setClipRect(0,0,screenW,screenH);
  
  tft.drawRect(0,0,screenW,screenH, 0x000000);
  tft.fillRect(0,0,screenW,screenH, 0x000000);

  tft.setCursor(80,80);
  tft.setTextColor( 0xFFF000, 0x000000);
  tft.setTextSize(3);

  tft.print("You Lose!");

  tft.setCursor(20,140);
  tft.setTextSize(2);
  tft.print("Martha is Disappointed");

  tft.updateScreen();

}


void winner(){
tft.setClipRect(0,0,screenW,screenH);

  
  tft.drawRect(0,0,screenW,screenH, 0x000000);
  tft.fillRect(0,0,screenW,screenH, 0x000000);

  tft.setCursor(80,80);
  tft.setTextColor( 0xFF0FF0, 0x000000);
  tft.setTextSize(3);

  tft.print("You WON!");

  tft.setCursor(30,140);
  tft.setTextSize(2);
  tft.print("Martha Rests Avenged!");

  tft.updateScreen();

}
