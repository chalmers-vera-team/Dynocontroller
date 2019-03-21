#include <Arduino.h>
#include <control.h>

long h = 0;

void setup()
{
  setupBrake();
}

void loop()
{
  if (DEBUG)
  {
    if (h >= 1000)
      debugMessage();
    h = (h + 1) % 1001;
  }

  updateBrake();

  
  delay(loopTime);
}
