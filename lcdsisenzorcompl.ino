#include <LiquidCrystal.h>  

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  

const int trigPin = 12;
const int echoPin = 13;
const int speaker = 9;

const int freq = 1100;

long duration;
int distance;

void setup() {
  lcd.begin(16, 2);    
  Serial.begin(9600);  


  pinMode(speaker, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  if (Serial.available()) {
    String teststr = Serial.readString();  
    teststr.trim();                        

    lcd.clear();
    while (teststr.length() > 0)
      if (teststr.length() > 16) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(teststr.substring(0, 16));
        teststr.remove(0, 16);
        lcd.setCursor(0, 1);
        lcd.print(teststr.substring(0, 16));
        teststr.remove(0, 16);
        delay(2800);
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(teststr.substring(0, 16));
        teststr.remove(0, 16);
        delay(2800);
      }
    

    lcd.clear();

        



      }
      {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH, 30000); 

  
  if (duration == 0) {
    Serial.println("Timeout occurred. Check connections and distances.");
  } else {
    
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);
  }

 
  delay(500);
      }

    if(distance <60)
      { digitalWrite(speaker,LOW);
        delay(1);
        digitalWrite(speaker, HIGH);   
        delay(1);
      }

              
}



