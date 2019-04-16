#include "config.h"
#include "control.h"

void setupPins() {
  Serial.begin(9600);
  pinMode(PIN_BRAKECONTROL, OUTPUT);
  pinMode(PIN_CONTROLAUTOINPUT,INPUT);
  pinMode(PIN_CONTROLMANUALINPUT, INPUT);
  pinMode(PIN_CONTROLMODEINPUT, INPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}


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




void information() {
  Serial.print("Manual input: "); Serial.println(analogRead(PIN_CONTROLMANUALINPUT)); 
  delay(1000);
  Serial.print("Auto input: "); Serial.println(analogRead(PIN_CONTROLAUTOINPUT));
  delay(1000);
  Serial.print("Mode input: "); Serial.println(digitalRead(PIN_CONTROLMODEINPUT));
  delay(1000);
  Serial.print("Power to brake: "); Serial.println(readInput());
  delay(3000);


}
