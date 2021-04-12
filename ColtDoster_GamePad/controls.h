#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[4] = {0, 1, 2, 3}; // holds teensy pin values for the buttons
int buttonBuffer[4] = {0, 0}; // holds the state of each button

int joyStickPins[2] = {A1, A0}; // teensy pin values for the joystick
int joyStickBuffer[2] = {0, 0}; // holds state for the joystick

int inputsTime = 250;

Metro inputsTimer = Metro(inputsTime); // a timer to only print 4 times a second.


void initControls(){
  for( int i = 0; i <4; i++){
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}


void getControls(){
  for(int i = 0; i <4; i++){            // gets and updates the values of the buttons
        buttons[i].update();
    if(buttons[i].fell()){buttonBuffer[i] = 1;} 
    else{buttonBuffer[i] = 0;}
    //else if(buttons[i].fell()){buttonBuffer[i] = 1;}
  }

//  for(int i = 0; i < 2; i++){
//    int joyStickValue = analogRead(joyStickPins[i]);
//    joyStickBuffer[i] = joyStickValue;
//  }


    // read the joytstick potentiometers
    int xJoyValue = analogRead(joyStickPins[0]);
    int yJoyValue = analogRead(joyStickPins[1]);

    // give them a directional value
    if(xJoyValue < 300){
      joyStickBuffer[0] = 1;
    } else if(xJoyValue > 700){
      joyStickBuffer[0] = -1;
    } else {
      joyStickBuffer[0] = 0;
    }

      if(yJoyValue < 300){
      joyStickBuffer[1] = -1;
    } else if(yJoyValue > 700){
      joyStickBuffer[1] = 1;
    } else {
      joyStickBuffer[1] = 0;
    }

//   if(inputsTimer.check()){
//    Serial.print(buttonBuffer[0]);
//      Serial.print("\t");
//    Serial.print(buttonBuffer[1]);
//      Serial.print("\t");
//    Serial.print(buttonBuffer[2]);
//      Serial.print("\t");
//    Serial.print(buttonBuffer[3]);
//      Serial.print("\t");
//    Serial.print(joyStickBuffer[0]);
//      Serial.print("\t");
//    Serial.print(joyStickBuffer[1]);
//      Serial.print("\t");
//    Serial.println();
//    }
}

//void printButtons(){
//
//  //Serial.println();
//}
//
//void printJoy(){
// 
//
//
//}
