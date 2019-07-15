#include "config.h"
#include "control.h"

void setup() {
  setupPins();   
  Serial.begin(9600);
}

void loop() {
  controlBrake(readInput());
  //information();
}
