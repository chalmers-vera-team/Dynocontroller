#ifndef CONTROL_H
#define CONTROL_H



// reads which mode
// 1 - auto
// 0 - manual
int readMode();


// Reads the input
// knows if in manual or auto mode
int readInput(); 

// Set the power to brake 0 - 255
void controlBrake(int power); 



#endif
