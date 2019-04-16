#include "config.h"
#include "control.h"

void setup() {
  pinMode(PIN_BRAKECONTROL, OUTPUT);
  pinMode(PIN_CONTROLAUTOINPUT,INPUT);
  pinMode(PIN_CONTROLMANUALINPUT, INPUT);
  pinMode(PIN_CONTROLMODEINPUT, INPUT);

}

void loop() {
  controlBrake(readInput());
}
