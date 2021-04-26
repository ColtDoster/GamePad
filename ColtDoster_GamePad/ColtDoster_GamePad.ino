//Martha Berry Madness
// Colt Doster || 03 Mar 2021
// CRT 360 Advanced Prototyping || Gamepad

int curMode = -2;

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "status.h" 
#include "hero.h"
#include "enemy.h"
#include "boss.h"
#include "fight.h"
#include "modes.h"


void setup(){

  randomSeed(analogRead(A9));
  
initScreen();
initControls();
initNeighbors();

}


void loop(){

getControls();
runMode();
checkFrame();

Serial.println(heroHealth);


}
