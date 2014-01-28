/************************************************************************************************
 **                         MiniMoto & GCDuino Code Example                                     **
 **     To set Direction: digitalWrite(M1_Dir or M2_Dir, HIGH = Reverse, LOW = Fowards);        **
 **     To set Speed: analogWrite(M1_Speed or M2_Speed, 0-250);                                 **
 **           NOTE: When going Forwards 0 = Slow, 250 = Fast                                    **
 **                            Reverse 0 = Fast, 250 = Slow                                     **
 **                                                                                             **
 **    Written by Rod Christian                                                    03/12/2013   **
 ************************************************************************************************/

#include <MiniMoto.h>


const int BUMP = 0;
boolean bumped = false;

void setup()
{
  initializeMiniMoto();

  digitalWrite(LED, HIGH);  //Turns LED On to let you know Code is running  
  attachInterrupt(BUMP, interuptHandler, CHANGE);

  LEDoff();
}

void loop()
{
  if(bumped) {
    LEDon();
    turn();
    LEDoff();
  }
  M_Fwd();
}

void interuptHandler()
{
  bumped = true;
}

void turn() { 
  M_Rev();
  delay(100);
  M_Stop();
  playMelody();
  M1_Fwd();
  M2_Rev();
  delay(400);  
  bumped = false;
}
