#include <Servo.h>

Servo myservo;

int pos = 0;    // variable to store the servo position

void setup() {
   pinMode(2, INPUT);
   pinMode(5, INPUT);
   pinMode(6, INPUT);
   pinMode(7, INPUT);
   
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
}

void loop() {
  int a = digitalRead(2);
  int b = digitalRead(5);
  int c = digitalRead(6);
  int d = digitalRead(7);
  
  if (a) {
    myservo.write(180);
  } else if (b) {
    myservo.write(120);
  } else if (c) {
    myservo.write(60);
  } else if (d) {
    myservo.write(0);
  }

  delay(200);
}
