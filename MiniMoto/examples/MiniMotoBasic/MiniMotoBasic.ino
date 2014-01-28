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

void setup()
{
  digitalWrite(LED, HIGH);  //Turns LED On to let you know Code is running
}

void loop()
{
  LEDon();
  M1_Rev();
  M2_Fwd();
  delay(10000);
  LEDoff();
  M_Rev();
  delay(2000);
  LEDon();
  M_Stop();
  delay(250);
  M_Fwd();
  LEDoff();
  delay(3000);
  M1_Fwd();
  M2_Rev();
}
