#define OFF 2
#define GREEN 3
#define AMBER 4
#define RED 5

#define RED_PIN 10    
#define GREEN_PIN 11

int colour = OFF;

void setup()  { 
  for(int i=OFF; i <= RED; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  off();
} 

void loop()  { 
  for(int i=OFF; i <= RED; i++) {
    if(digitalRead(i) == LOW && colour != i)
      changeLedTo(i);
  }  
}

void changeLedTo(int colour) {
  switch(colour) {
  case GREEN: 
    green(); 
    break;
  case AMBER: 
    amber();
    break;
  case RED:
    red();
    break;
  default:
    off();
  }
}

void off() {
  colour = OFF;
  analogWrite(RED_PIN, 0);         
  analogWrite(GREEN_PIN, 0);    
}

void green() {
  colour = GREEN;
  analogWrite(RED_PIN, 0);         
  analogWrite(GREEN_PIN, 255);     
}

void amber() {
  colour = AMBER;
  analogWrite(RED_PIN, 255);         
  analogWrite(GREEN_PIN, 100);         
}

void red() {
  colour = RED;
  analogWrite(RED_PIN, 255);         
  analogWrite(GREEN_PIN, 0);         
}








