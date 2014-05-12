/*
//Add these BEFORE your setup function.
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

//Make your loop function look like below:
void loop()  
{ 
  // set the brightness of the green LED:
  analogWrite(greenLED, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) 
  {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 50 milliseconds to see the dimming effect    
  delay(50);                            
}

*/
