#include <Arduino.h>
#include "Utils.h"

// Map Analog eightBitues to a real UV index.
int analogValueToUVIndex(int a) {
  return eightBitToUVIndex(analogToEightBit(a));
}

int analogToEightBit(int analogeightBitue) {
  return map(analogeightBitue, 0, 1023, 0, 255);  
}

int eightBitToUVIndex(int eightBit) {

  // from http://www.dfrobot.com/wiki/index.php/UV_Sensor_(SKU:TOY0044)  

  int uvIndex;

  // can't just do this unfortunately
  //  if(eightBit < 46) {
  //    uvIndex = 0;
  //  } else {
  //    uvIndex =  map(eightBit,46, 240, 1, 11); 
  //  }

  // Don't think it's quite linear so have just mapped this manually
  if(eightBit < 46) {
    uvIndex = 0; 
  } 
  else if(eightBit < 65) {
    uvIndex = 1; 
  } 
  else if(eightBit < 83) {
    uvIndex = 2; 
  }
  else if(eightBit < 103) {
    uvIndex = 3; 
  }
  else if(eightBit < 124) {
    uvIndex = 4; 
  }
  else if(eightBit < 142) {
    uvIndex = 5; 
  }
  else if(eightBit < 162) {
    uvIndex = 6; 
  }
  else if(eightBit < 180) {
    uvIndex = 7; 
  }
  else if(eightBit < 200) {
    uvIndex = 8; 
  }
  else if(eightBit < 221) {
    uvIndex = 9; 
  }
  else if(eightBit < 240) {
    uvIndex = 10; 
  }
  else {
    uvIndex = 11; 
  } 

  return uvIndex;
}


