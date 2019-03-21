/**
 * @file main.cpp
 * @author Oskar Johansson (oskar@irisnet.se)
 * @brief 
 * @version 0.1
 * @date 2019-03-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
