#include "config.h"
#include "control.h"

void setup() {
  pinMode(PIN_BRAKECONTROL, OUTPUT);
  pinMode(PIN_CONTROLAUTOINPUT,INPUT);
  pinMode(PIN_CONTROLMANUALINPUT, INPUT);
  pinMode(PIN_CONTROLMODEINPUT, INPUT);
  delay(1000);
}

void loop() {
  controlBrake(readInput());
}
