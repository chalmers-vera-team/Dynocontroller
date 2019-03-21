#ifndef CONTROL_H
#define CONTROL_H

#include <Arduino.h>
#include <config.h>

/**
 * Setups the brake with all neccesary pins.
 */
void setupBrake();

/**
 * Setups 
 */
void setupPin();

/**
 * 
 */
void updateBrake();

/**
 * Sets the amount of power to brake
 * 0 - 255
 */
void setBrake(int power);

/**
 * Stops the brake by set
 * output to 0
 */
void stopBrake();

/**
 * Returnsm2 how much brakepower 
 * inputs requers
 * from POT/PWM/Serial depending
 * on setup
 */
int getBrakePower();

/**
 * Reads input
 */
int readInput();

int controlFromSerial();

int controlFromAuto();

String readSerial();

void checkControlMode();

void checkControlMode(String cmd);


int controlFromExternal();

/**
 * Controls from manual input
 * in this case an potentiometer
 */
int controlFromManual();

/**
 * Call this to show 
 * init message with
 * info about the system
 */
void initMessage();


/**
 * DEBUG INFO
 * Info about everything you need to know about 
 * the system. Pins, current output, current input
 */
void debugMessage();

#endif