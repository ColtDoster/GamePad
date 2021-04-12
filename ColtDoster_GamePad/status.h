
boolean statusDrawn = false;

void statusBar(int statusX, int statusY, int statusW, int statusH){

  if(statusDrawn == false){
  tft.drawRect(statusX, statusY, statusW, statusH, 0x0000FF);
  tft.fillRect(statusX, statusY, statusW, statusH, 0x0000FF);
  tft.updateScreen();
  } 

  statusDrawn = true;
}
