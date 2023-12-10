const int motor1A = 10;
const int motor1B = 9;
const int motor2A = 7;
const int motor2B = 8;
const int motorEn1 = 11;
const int motorEn2 = 6;
const int joyX = A0;
const int joyY = A1;


const int joyThreshold = 35;

void setup() {
  
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  
  int xAxisValue = analogRead(joyX);
  int yAxisValue = analogRead(joyY);

  
  if (xAxisValue > (512 + joyThreshold)) {
    
    digitalWrite(motorEn1, HIGH);
    digitalWrite(motorEn2 , HIGH);
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  } else if (xAxisValue < (512 - joyThreshold)) {
    
    digitalWrite(motorEn1, HIGH);
    digitalWrite(motorEn2, HIGH);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
  } else {
    
     digitalWrite(motorEn1, LOW);
    digitalWrite(motorEn2, LOW);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
  }
 if(xAxisValue<(517-joyThreshold) && (yAxisValue<(493-joyThreshold)))// DREAPTA
 {
   digitalWrite(motorEn1, HIGH);
    digitalWrite(motorEn2, LOW);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
 }
else if(xAxisValue<(517+joyThreshold) && (yAxisValue>(493+joyThreshold))) //STANGA
{
    digitalWrite(motorEn1, LOW);
    digitalWrite(motorEn2, HIGH);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);

  
  
}
}
