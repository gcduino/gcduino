// Summertime on the Gold Coast is particularly hot and sticky. We also 
// have to watch our skin for the high UV levels. 
// This example is using a Temp/Humidy sensor along with a UV sensor and a
// Real Time Clock (RTC) to log these important statistics to a LCD screen
// and also push out to the network to log them in an external database

#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  tempHumid();
  uv();
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
    Serial.println("Failed to read from DHT");
  } 
  else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}

//
// Read the UV sensor (GUVA-S12SD)
//
void uv() {
  int u;
  u = analogRead(A0);//connect UV sensors to Analog 0      
  Serial.print("UV Index: ");
  Serial.println(analogValueToUVIndex(u));
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





