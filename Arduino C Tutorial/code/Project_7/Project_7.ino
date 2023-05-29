/*
  keyestudio Nano Inventor Starter Kit
  Project 7 Buzzer
  http://www.keyestudio.com
*/
int buzzer = 3; //Define buzzer connecting to D3 pin
void setup() {
  pinMode(buzzer, OUTPUT);//Set the output mode
}

void loop() {
  digitalWrite(buzzer, HIGH); //D3 pin outputs a high level to cause the buzzer to emit sound
  delay(1000);	//Delay 1000ms
  digitalWrite(buzzer, LOW); //D3 pin outputs a low level to prevent the buzzer to emit sound
  delay(1000);
}