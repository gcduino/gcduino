#define M1_Speed  6   //Speed
#define M1_Dir  7   //Direction
#define M2_Speed 5   //Speed
#define M2_Dir 4   //Direction

#define LED A0

int Max_Speed = 250;  // 0 = Stopped, 250 = Fast 

void setup()
{
  pinMode(M1_Speed, OUTPUT);
  pinMode(M1_Dir, OUTPUT);
  pinMode(M2_Speed, OUTPUT);
  pinMode(M2_Dir, OUTPUT); 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop()
{
  Serial.println("M1 HIGH");
  analogWrite(M1_Speed, 250-Max_Speed);
  digitalWrite(M1_Dir, HIGH);
  delay(2000);
  digitalWrite(M1_Speed, LOW);
  digitalWrite(M1_Dir, LOW);
  delay(1000);
  Serial.println("M1 LOW");
  analogWrite(M1_Speed, Max_Speed);
  digitalWrite(M1_Dir, LOW);
  delay(2000);
  digitalWrite(M1_Speed, LOW);
  digitalWrite(M1_Dir, LOW);
  delay(1000);
  Serial.println("M2 HIGH");
  analogWrite(M2_Speed, 250-Max_Speed);
  digitalWrite(M2_Dir, HIGH);
  delay(2000);
  digitalWrite(M2_Speed, LOW);
  digitalWrite(M2_Dir, LOW);
  delay(1000);
  Serial.println("M2 LOW");
  analogWrite(M2_Speed, Max_Speed);
  digitalWrite(M2_Dir, LOW);
  delay(2000);
  digitalWrite(M2_Speed, LOW);
  digitalWrite(M2_Dir, LOW);
  delay(1000);
}


