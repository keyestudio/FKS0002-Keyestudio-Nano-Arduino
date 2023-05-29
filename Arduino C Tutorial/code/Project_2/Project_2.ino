/*
  keyestudio Nano Inventor Starter Kit
  Project 2 Star Breathing Light
  http://www.keyestudio.com
*/
int ledPin = 3; // Define LED as digital port 3
void setup () {
  pinMode (ledPin, OUTPUT); // Initialize LED to output mode
}
void loop () {
  for (int i = 0; i < 255; i++) {	//for loop statement
    analogWrite (ledPin, i); //led gradually lights up
    delay (10); // Delay 10ms
  }
  for (int i = 0; i < 255; i--) {
    analogWrite (ledPin, i); // led gradually goes off
    delay (10); // Delay 10ms
  }
}