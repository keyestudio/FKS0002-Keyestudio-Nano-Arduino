/*
  keyestudio Nano Inventor Starter Kit
  Project 12 Servo
  http://www.keyestudio.com
*/
#include <Servo.h>  //Servo library
Servo myservo;
void setup() {
  myservo.attach(9);//Set the control pin of servo to D9
}

void loop() {
  for (int pos = 0; pos < 180; pos++) {  //Control the servo to rotate from 0° to 180° by "for"loop.
    myservo.write(pos); //Rotate to angle of pos
    delay(15);  //Add a delay to slow the rotation
  }
  for (int pos = 180; pos > 0; pos--) {		//Control the servo to rotate from 180° to 0° by "for"loop.
    myservo.write(pos);
    delay(15);
  }
  delay(2000);//Wait 2s
}