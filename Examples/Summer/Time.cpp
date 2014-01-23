#include <Arduino.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#include "Utils.h"

// Get time from RTC and display
void displayTime(LiquidCrystal lcd) {
  tmElements_t tm;

  char dateTimeText[17];

  if (RTC.read(tm)) {
    snprintf(dateTimeText, 17, "%02d%02d%02d %02d:%02d:%02d", tmYearToY2k(tm.Year), tm.Month, tm.Day, tm.Hour, tm.Minute, tm.Second);
    lcd.print(dateTimeText);
  } 
  else {
    if (RTC.chipPresent()) {
      lcd.print("Run RTC Set Time");
    } 
    else {
      lcd.print("RTC Read Error");
    }
    delay(9000);
  }
}

