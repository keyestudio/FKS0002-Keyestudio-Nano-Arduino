/*
  keyestudio Nano Inventor Starter Kit
  Project 3 SOS Distress Device
  http://www.keyestudio.com
*/
int ledPin = 3;  //Define led to pin 3
 
void setup() {
pinMode(ledPin, OUTPUT);
}
 
void loop() {
// Three quick blinks mean an “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(150);                           //Delay 150ms
digitalWrite(ledPin,LOW);             //Set LED to turn off
delay(100);                           //Delay 100ms
}
 
//delay 200ms to generate the space between letters
delay(200);
 
//Three slow blinks mean an “O”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(400);                           //Delay 400ms
digitalWrite(ledPin,LOW);             //Set LED to turn off
delay(200);                           //Delay 200ms
}
 
//Delay 100ms to generate the space between letters
delay(100);
 
// Three quick blinks mean an “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(150);                           //Delay 150ms
digitalWrite(ledPin,LOW);             //Set LEDms
delay(100);                           //Delay 100ms
} 
// Wait 5s before repeating "S.0.S"
delay(5000);
}