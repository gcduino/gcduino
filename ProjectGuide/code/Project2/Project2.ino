int greenLED = 10;
int redLED = 11;    //ADDED

// How many times will the code in the setup function run (between "{" & "}")
void setup() 
{                
  // What does "OUTPUT" mean?
  pinMode(greenLED, OUTPUT); 
  pinMode(redLED, OUTPUT);  //ADDED
}

// How many times does the code in the loop function run?
void loop() 
{
  digitalWrite(greenLED, HIGH);   
  digitalWrite(redLED, HIGH);     //ADDED
  delay(1000);                    
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);      //ADDED
  delay(1000);                    
}

//Can you make it so they alternate? (One ON & One off)
//Can you make it so the green blinks twice and much as the red?
