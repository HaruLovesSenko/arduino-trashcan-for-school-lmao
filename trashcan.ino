#include <Servo.h>

Servo servo;

const int trigPin = 13;
const int echoPin = 12;
const int servoPin = 3;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  servo.attach(servoPin);
  servo.write(0);
  Serial.begin(9600);
}

void loop() {
  delay(10);
  int distance = checkDistance();
  if (distance < 11) {
    for (int i=0;i<180; i++) {
      servo.write(i);
      delay(10);
    }
    distance = checkDistance();
    while (distance < 11) {
      distance = checkDistance();
      delay(100);
    }
    delay(3000);
    for (int i=180; i>0; i--) {
      servo.write(i);  
      delay(10);
    }
  }
}

int checkDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration*0.034/2;

  return distance;
}
