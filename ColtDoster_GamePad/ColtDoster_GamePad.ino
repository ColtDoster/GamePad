//Martha Berry Madness
// Colt Doster || 03 Mar 2021
// CRT 360 Advanced Prototyping || Gamepad

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "hero.h"


void setup(){
  
initScreen();
initControls();

}

void loop(){


//checkFrame();

//screenTest();
//drawLevel(0);
drawHero();
tft.updateScreen();

getControls();


}
