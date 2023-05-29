/*
  keyestudio Nano Inventor Starter Kit
  Project 1 Blinking
  http://www.keyestudio.com
*/
int ledPin = 3; //Define LED to connect with pin D3
void setup() {
  pinMode(ledPin, OUTPUT);//Set the mode to output
}

void loop() {
  digitalWrite(ledPin, HIGH); //Output a high level, LED lights up.
  delay(1000);//Delay 1000ms
  digitalWrite(ledPin, LOW); //Output a low level, LED goes off.
  delay(1000);

}
