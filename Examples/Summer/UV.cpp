#include <Arduino.h>
#include <LiquidCrystal.h>

#include "Utils.h"

//
// Read the UV sensor (GUVA-S12SD)
//
void displayUvIndex(LiquidCrystal lcd) {
  int u;
  u = analogRead(A0); //connect UV sensors to Analog 0      
  char uvIndexString[4];
  snprintf(uvIndexString, 4, "%02d ", analogValueToUVIndex(u));
  lcd.print(uvIndexString);
}
