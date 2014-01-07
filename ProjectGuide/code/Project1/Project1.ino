// Pin 10 is connected to the postive(Long Leg) of the LED.
// The short leg to a 220 Ohm Resistor (Red, Red, Brown) and then to ground.
// So we give Pin 10 a descriptive name:
int greenLED = 10;

// the setup routine ONLY runs once when the GCDuino is reset:
void setup() 
{                
  // initialize the digital pin as an output.
  pinMode(greenLED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() 
{
  digitalWrite(greenLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                    // wait for a second
  digitalWrite(greenLED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                    // wait for a second
}

//Can you make the LED stay ON longer than it is OFF?
//Can you make it blink faster?
//How fast can it blink?
//What would change in the code if we moved the wire connecting the LED to the GCD?
//What does the "~" sign mean infront of the pin number?
