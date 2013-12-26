
//This Program Toggles which LED is lit every Button Press
//These Variables Won't Change:  (Constant)
const int greenLED = 10;
const int redLED = 11;     
const int button = 13;   
//These Variables Will:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int ledState = 0;            // current state of the LED's

void setup() 
{                
  pinMode(greenLED, OUTPUT);    
  pinMode(redLED, OUTPUT);      
  pinMode(button, INPUT);      
}

void loop() 
{
  buttonState = digitalRead(button);  //Read's and Store's the button state
  if (buttonState != lastButtonState)  //If it does not equal the previous Read
  {
    if (buttonState == HIGH)  //If the button is HIGH (Pushed)
    {
      if(ledState == 1)  
      {                                
        digitalWrite(greenLED, HIGH);  
        digitalWrite(redLED, LOW);  
        ledState = 0; 
      } else                           
      {                                
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);  
        ledState = 1;   
      }    
    }
  }
  lastButtonState = buttonState; //Store’s this Read as the last state
  delay(50);       //Ask about debounce
}
