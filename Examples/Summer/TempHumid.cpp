#include <DHT.h>
#include <LiquidCrystal.h>

#include "Utils.h"

#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

void startTempHumiditySensor() {
  dht.begin();
}

//
// Read the DHT22 Temp/Humidity sensor
//
void displayTempHumidity(LiquidCrystal lcd) {  
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
