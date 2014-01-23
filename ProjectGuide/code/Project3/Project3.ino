int greenLED = 10;
int redLED = 11;    
int button = 13;     //ADDED

void setup() 
{                
  pinMode(greenLED, OUTPUT); 
  pinMode(redLED, OUTPUT);  
  pinMode(button, INPUT);     //ADDED
}

void loop() //Notice I have removed the delay commands.
{
  if(digitalRead(button) == HIGH)    //ADDED
  {                                  //ADDED
    digitalWrite(greenLED, HIGH);   
    digitalWrite(redLED, LOW);     
  } 
  else                             //ADDED
  {                                  //ADDED
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);      
  }                                  //ADDED
}

//In the Advance you will make them toggle which LED is On

