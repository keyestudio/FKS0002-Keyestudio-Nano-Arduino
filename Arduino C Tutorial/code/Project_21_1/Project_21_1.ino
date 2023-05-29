/*
  keyestudio Nano Inventor Starter Kit
  Project 21.1 Voice Control Light
  http://www.keyestudio.com
*/
int sound = A0;
void setup(){
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(sound);
  Serial.println(value);
}