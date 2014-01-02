#define M1_Speed  6   //Speed
#define M1_Dir  7   //Direction
#define M2_Speed 5   //Speed
#define M2_Dir 4   //Direction

#define LED A0

void setup()
{
  pinMode(M1_Speed, OUTPUT);
  pinMode(M1_Dir, OUTPUT);
  pinMode(M2_Speed, OUTPUT);
  pinMode(M2_Dir, OUTPUT); 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(5000);
}

void loop()
{
  spinLeft();
  delay(5000);
  spinRight();
  delay(5000);
  left();
  delay(2000);
  right();
  delay(2000);
  forward();
  delay(2000);
  back();
  delay(2000);


}

void spinLeft() 
{
  halfSpeed();
  digitalWrite(M1_Dir, LOW);
  digitalWrite(M2_Dir, HIGH);
}

void spinRight()
{
  halfSpeed();
  digitalWrite(M1_Dir, HIGH);
  digitalWrite(M2_Dir, LOW);
}

void left() 
{
  halfSpeed();
  analogWrite(M1_Speed, 0);  
  digitalWrite(M1_Dir, LOW);
  digitalWrite(M2_Dir, HIGH);
}

void right() 
{
  halfSpeed();
  analogWrite(M2_Speed, 0);  
  digitalWrite(M1_Dir, HIGH);
  digitalWrite(M2_Dir, LOW);
}


void forward() 
{
  halfSpeed();
  digitalWrite(M1_Dir, HIGH);
  digitalWrite(M2_Dir, HIGH);
}

void back()
{
  halfSpeed();
  digitalWrite(M1_Dir, LOW);
  digitalWrite(M2_Dir, LOW);
}

void halt() 
{
  analogWrite(M1_Speed, 0);
  analogWrite(M2_Speed, 0);
}

void halfSpeed()
{
  analogWrite(M1_Speed, 125);
  analogWrite(M2_Speed, 125);
}

void fullSpeed() {
  analogWrite(M1_Speed, 250);
  analogWrite(M2_Speed, 250);
}




