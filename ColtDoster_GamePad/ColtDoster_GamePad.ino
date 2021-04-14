//Martha Berry Madness
// Colt Doster || 03 Mar 2021
// CRT 360 Advanced Prototyping || Gamepad

int curMode = -1;

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "status.h" 
#include "hero.h"
#include "enemy.h"
#include "modes.h"


void setup(){
  
initScreen();
initControls();
initNeighbors();

}


void loop(){

getControls();
runMode();
checkFrame();


}
