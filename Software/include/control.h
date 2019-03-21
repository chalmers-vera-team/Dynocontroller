/**
 * @file control.h
 * @author Oskar Johansson (oskar@irisnet.se)
 * @brief 
 * This is a quite big control-file. The thought about it is to make it easier to 
 * use later on.  
 * @version 0.1
 * @date 2019-03-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CONTROL_H
#define CONTROL_H
#include <Arduino.h>
#include <config.h>

/**
 * @brief 
 * This will setup the neccesary pins. 
 * Also send a message if connected to Serial. 
 */
void setupBrake();

/**
 * @brief 
 * To be used in combination with @setupBrake
 * This will setup the pins that are used. 
 * 
 */
void setupPin();

/**
 * @brief 
 * Reads input and set controlsignal to dyno. 
 * 
 */
void updateBrake();

/**
 * @brief Set the Brake object
 * Sets the control signal
 * @param power - how much brake 0 - 255
 */
void setBrake(int power);

/**
 * @brief 
 * Stops the dyno. 
 */
void stopBrake();

/**
 * @brief 
 * Read input to 
 * @return int 
 */
int getBrakePower();

/**
 * @brief 
 * 
 * @return int 
 */
int readInput();

/**
 * @brief 
 * 
 * @return int 
 */
int controlFromSerial();

/**
 * @brief 
 * 
 * @return int 
 */
int controlFromAuto();

/**
 * @brief 
 * 
 * @return String 
 */
String readSerial();

/**
 * @brief 
 * 
 */
void checkControlMode();

/**
 * @brief 
 * 
 * @param cmd 
 */
void checkControlMode(String cmd);

/**
 * @brief 
 * Control from serial. 
 * @return int 
 */
int controlFromExternal();

/**
 * @brief 
 * Control dyno manual. Now by using a potentiometer 
 * 
 * @return int, the value of how much the controlsignal to brake 
 * should be
 */
int controlFromManual();

/**
 * @brief 
 * This will show an message about the software 
 */
void initMessage();

/**
 * @brief 
 * Info about everything you need to know about 
 * the system. Pins, current output, current input
 */

void debugMessage();

#endif