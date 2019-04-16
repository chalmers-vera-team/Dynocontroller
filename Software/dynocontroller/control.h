#ifndef CONTROL_H
#define CONTROL_H
#include <Arduino.h>


// Setup all neccesary pins
void setupPins(); 

// reads which mode
// 1 - auto
// 0 - manual
int readMode();


// Reads the input
// knows if in manual or auto mode
// Return 0 - 255
int readInput(); 

// Set the power to brake 0 - 255
void controlBrake(int power); 

// Write out some information to serial 
void information();

#endif
