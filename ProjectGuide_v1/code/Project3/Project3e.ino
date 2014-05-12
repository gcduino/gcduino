/*
// Add these Variables above the setup function
int buttonState = 0:
int lastButtonState = 0;
int ledState = 0;

//Modify your loop function to look like below:

void loop() 
{
  buttonState = digitalRead(button);     //Reads and Store's the button's State
  if (buttonState != lastButtonState)   //If it does not equal the previous Read
  {
    if (buttonState == HIGH)            //if the button is HIGH (Pushed)
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
  lastButtonState = buttonState; //Store this Read as the last State
  delay(50);      //Ask about debounce
}  

*/
