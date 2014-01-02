// Summertime on the Gold Coast is particularly hot and sticky. We also 
// have to watch our skin for the high UV levels. 
// This example is using a Temp/Humidy sensor along with a UV sensor and a
// Real Time Clock (RTC) to log these important statistics to a LCD screen
// and also push out to the network to log them in an external database

#include "DHT.h"
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 4, 5, 6, 7); // Had to move standar LCD pins so they didn't clash with RTC I2C pin 2

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hai peeps!");
  lcd.setCursor(0, 1);
  lcd.print("UV/Humidity/Temp");
  dht.begin();
  delay(2000);
}

void loop() {
  lcd.setCursor(0, 0);
  getTime();
  lcd.setCursor(0, 1);
  uv();
  tempHumid();
  delay(1000);
} 

//
// Read the DHT22 Temp/Humidity sensor
//
void tempHumid() {  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    lcd.print("DHT Fail");
  } 
  else {
    lcd.print(h);
    lcd.print("% ");
    lcd.print(t);
    lcd.print("C");
  }
}

//
// Read the UV sensor (GUVA-S12SD)
//
void uv() {
  int u;
  u = analogRead(A0); //connect UV sensors to Analog 0      
  char uvIndexString[4];
  snprintf(uvIndexString, 4, "%02d ", analogValueToUVIndex(u));
  lcd.print(uvIndexString);
}

// Map Analog values to a real UV index.
int analogValueToUVIndex(int a) {

  // from http://www.dfrobot.com/wiki/index.php/UV_Sensor_(SKU:TOY0044)  
  int uv = 0;
  int val = map(a, 0, 1023, 0, 255);  

  // Don't think it's quite linear so have just mapped this manually
  if(val >= 46) {
    uv = 1; 
  } 
  else if(val >= 65) {
    uv = 2; 
  }
  else if(val >= 83) {
    uv = 3; 
  }
  else if(val >= 103) {
    uv = 4; 
  }
  else if(val >= 124) {
    uv = 5; 
  }
  else if(val >= 142) {
    uv = 6; 
  }
  else if(val >= 162) {
    uv = 7; 
  }
  else if(val >= 180) {
    uv = 8; 
  }
  else if(val >= 200) {
    uv = 9; 
  }
  else if(val >= 221) {
    uv = 10; 
  }
  else if(val >= 240) {
    uv = 11; 
  }

  return uv;
}

// Get time from RTC and display
void getTime() {
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




