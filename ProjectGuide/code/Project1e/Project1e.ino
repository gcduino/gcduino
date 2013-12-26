//This Program Fades the green LED
//These Variables Won't Change:  (Constant)
const int greenLED = 10;
//These Variables Will:
int brightness = 0;         // current LED brightness
int fadeAmount = 5;     // How much to fade by

void setup() 
{                
   pinMode(greenLED, OUTPUT);    
}

void loop() 
{
  analogWrite(greenLED, brightness);  //Writes the brightness amount to the LED
  brightness = brightness + fadeAmount); //adds the fade Amount to the Brightness
  if (brightness == 0 || brightness == 255) 
  {
     fadeAmount = -fadeAmount ; //Changes the fade Amount 
  }
  delay(50);
}
