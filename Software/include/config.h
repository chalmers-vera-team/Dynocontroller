/**
 * @file config.h
 * @author Oskar Johansson (oskar@irisnet.se)
 * @brief 
 * @version 0.1
 * @date 2019-03-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef CONFIG_H
#define CONFIG_H

#define VERSIONDATE 20190321

/**
 * SETUP 
 */

// BAUDRATE for Serial communication
#define BAUDRATE 9600

// If in debug mode, 1 - debug, 0 - none
#define DEBUG 1

// Mode for controller
#define controlPOT 0
#define controlAUTO 1

// The initialmode
#define INITIAL_MODE 1

// minimum time in loop (ms)
#define loopTime 1

// Max output to brake
#define maxOutput 255
// Min output to brake 
#define minOutput 0
/**
 * OUTPUT PINS
 */
// The output to N-Mosfet
#define pinBrakeControlOutput 3

/**
 * INPUT PINS 
 */

// Analog read from YourDyno
#define pinBrakeControlAuto 4

// Analog read from potentiometer
#define pinBrakeControlManualInput 2
// If invert manualinput, 0 false, 1 true
#define invertManualInput 1

// Digital input from switch
#define pinBrakeModeSwitchInput 8

//  Analog pin for current measure
#define pinBrakeCurrentMeasure 0


/**
 * For PID regulation.
 * To be added
 */
#define Fp 0.0
#define Fi 0.0
#define Fd 0.0
// How many updates per second (Hz)
#define updateFrequenzeHZ 100
// How many reads from currentsensor
#define numOfReads 10

#endif