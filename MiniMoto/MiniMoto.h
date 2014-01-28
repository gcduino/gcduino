#ifndef MINIMOTO_H
#define MINIMOTO_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

const int M1_Speed = 6;  //Speed
const int M1_Dir = 7;    //Direction
const int M2_Speed = 5;   //Speed
const int M2_Dir = 4;     //Direction

const int LED = 9;   // GCDuino Built-in LED

void initializeMiniMoto(); 
void initializeMiniMoto(int); 
void changeMaxSpeed(int); 

void LEDon();
void LEDoff();

void M1_Rev();
void M1_Fwd();
void M1_Stop();
void M2_Rev();
void M2_Fwd();
void M2_Stop();

//Control Both Motors
void M_Rev();
void M_Fwd();
void M_Stop();

#endif
