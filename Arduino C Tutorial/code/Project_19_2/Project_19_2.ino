/*
  keyestudio Nano Inventor Starter Kit
  Project 19.2 Dimming Lamp
  http://www.keyestudio.com
*/
int led = 3;		//Define LED to D3 
int pot = A0;		//Definr pot to A0 
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);		//Set pin D3 to output 
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pot);
  int led_val = map(value,0,1023,0,255);  //Equally-proportionally convert the range of potentiometer analog value to the range we need 
  analogWrite(led,led_val);
}