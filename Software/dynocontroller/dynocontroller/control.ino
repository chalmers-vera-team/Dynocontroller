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
}

void controlBrake(int power) {
  analogWrite(PIN_BRAKECONTROL,power);
}
