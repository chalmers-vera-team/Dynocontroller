#include <control.h>

int controlMode;
int lastOutput = 0; 
/**
 * Setup all pins 
 * also see which mode is to be used
 */

void setupBrake()
{
  // Sets controlmode
  checkControlMode();
  // Pin setup
  setupPin();
  // Stops the brake
  stopBrake();
  // Serial init
  Serial.begin(BAUDRATE);
  // Serial message
  initMessage();
}

/**
 * Called from main function. 
 * This sets the brake power
 */
void updateBrake()
{
  setBrake(getBrakePower());
}
/**
 * Sets the output on brake 
 */
void setBrake(int power)
{
  // Guards if brake has som restrictions. 
  if(power < minOutput)
    power = minOutput;
  if(power > maxOutput)
    power = maxOutput;
  lastOutput = power;   
  analogWrite(pinBrakeControlOutput, power);
}

void stopBrake()
{
  setBrake(0);
}

int readInput()
{
  // checks which mode to run in
  checkControlMode();
  switch (controlMode)
  {
  case controlPOT:
    return controlFromManual();
  case controlAUTO:
    return controlFromAuto();
  }
  return 0;
}

int getBrakePower()
{
  return readInput();
}

/* 
 * Checks which mode to control in
 * manual or auto
 */
void checkControlMode()
{
  controlMode = digitalRead(pinBrakeModeSwitchInput);
}

/**
 *  This will control the brake using
 *  an analog input from the DynoRegulator
 */
int controlFromAuto()
{
  return ((analogRead(pinBrakeControlAuto)) >> 2);
}

/**
 * From potentiometer
 */
int controlFromManual()
{
  if (invertManualInput)
    return ((1023 - analogRead(pinBrakeControlManualInput)) >> 2);
  return ((analogRead(pinBrakeControlManualInput)) >> 2);
}

/**
 * Setup the neccesary digital pins
 */
void setupPin()
{
  pinMode(pinBrakeControlOutput, OUTPUT);
  pinMode(pinBrakeModeSwitchInput, INPUT);
}

/**
 * DEBUG INFO
 * Info about everything you need to know about 
 * the system. Pins, current output, current input
 */
void debugMessage()
{
  Serial.println("DEBUG INFO");
  Serial.print("Last output: "); Serial.print(lastOutput);
  Serial.print(" From YourDyno: "); Serial.print(controlFromAuto());
  Serial.print(" From Manual: "); Serial.print(controlFromManual());
  Serial.print(" Mode: "); Serial.print(digitalRead(pinBrakeModeSwitchInput));
  Serial.print(" Current measure: ");Serial.print(analogRead(pinBrakeCurrentMeasure));
  Serial.print("\n");
}

/**
 * A start message to the Serial Monitor
 */
void initMessage()
{
  Serial.println("WELCOME TO CHALMERS VERA TEAM'S BRAKEBENCH");

  Serial.println("------------------------------------------- \n \n");
  Serial.println("Info about this system \n");

  // CONTROL MODE, INFO AND COMMANDS
  Serial.println("Last edited:");
  Serial.println(VERSIONDATE);
  Serial.println(" ");
  Serial.println(" ");

  // PINS
  Serial.print("Pins: \n Brake output: ");
  Serial.println(pinBrakeControlOutput);
  Serial.print("Brake input from YourDyno");
  Serial.println(pinBrakeControlAuto);
  Serial.print("Manual brake input: ");
  Serial.println(pinBrakeControlManualInput);
  Serial.print("Brake mode switch input: ");
  Serial.println(pinBrakeModeSwitchInput);

  Serial.print("\n ------------------------------------------- \n \n");
}