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
  analogWrite(M1_Speed, 125);
  analogWrite(M2_Speed, 125);
  digitalWrite(LED, HIGH);
}

void loop()
{
  digitalWrite(M1_Dir, LOW);
  digitalWrite(M2_Dir, LOW);
  delay(1000);
  digitalWrite(M1_Dir, HIGH);
  digitalWrite(M2_Dir, HIGH);
  delay(1000);
 }


