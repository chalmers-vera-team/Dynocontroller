#include "config.h"
#include "control.h"

void setup() {
  setupPins();   
}

void loop() {
  controlBrake(readInput());
  //information();
}
