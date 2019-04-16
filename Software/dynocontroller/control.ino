#include "config.h"
#include "control.h"


int readMode() {
  return digitalRead(PIN_CONTROLMODEINPUT);
}

int readInput() {
  int power = 0;
  if(readMode())
    power = analogRead(PIN_CONTROLAUTOINPUT);
  else {
    if(INVERTMANUALINPUT)
      power = 1024 - analogRead(PIN_CONTROLMANUALINPUT);  
    else
      power = analogRead(PIN_CONTROLMANUALINPUT);  
  }
  // Analogread is 10 bit, analogwrite is only 8 bit
  // shifting 2 steps 
  power = power >> 2;
  return power; 
}

void controlBrake(int power) {
  //Some small guards
  if(power > 255) power = 255;
  if(power < 0) power = 0;
       
  analogWrite(PIN_BRAKECONTROL,power);
}
