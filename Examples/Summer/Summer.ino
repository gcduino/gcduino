// Summertime on the Gold Coast is particularly hot and sticky. We also 
// have to watch our skin for the high UV levels. 
// This example is using a Temp/Humidy sensor along with a UV sensor and a
// Real Time Clock (RTC) to log these important statistics to a LCD screen
// and also push out to the network to log them in an external database

#include <LiquidCrystal.h>
#include <ArduinoUnit.h>
#include "Utils.h"

LiquidCrystal lcd(12, 11, 4, 5, 6, 7); // Had to move standard LCD pins so they didn't clash with RTC I2C pin 2

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hai peeps!");
  lcd.setCursor(0, 1);
  lcd.print("UV/Humidity/Temp");
  startDht();
  delay(2000);
}

void loop() {
  // Run the tests first
  Test::run();
  
  lcd.setCursor(0, 0);
  getTime(lcd);
  lcd.setCursor(0, 1);
  uv(lcd);
  tempHumid(lcd);
  delay(1000);
} 

