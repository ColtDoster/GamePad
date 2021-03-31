//Martha Berry Madness
// Colt Doster || 03 Mar 2021
// CRT 360 Advanced Prototyping || Gamepad

#include "frame.h"
#include "screen.h"
#include "tile.h"


void setup(){
  
initScreen();

}

void loop(){


checkFrame();

//screenTest();

drawLevel(0);

tft.updateScreen();

}
