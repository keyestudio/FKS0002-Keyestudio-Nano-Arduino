/*
  keyestudio Nano Inventor Starter Kit
  Project 8.1 Music Performer
  http://www.keyestudio.com
*/
int beeppin = 6; //Define the speaker pin to D6
void setup() {
  pinMode(beeppin, OUTPUT);//Define the amplifier digital port to output mode
}

void loop() {
  tone(beeppin, 262);//Flat DO plays 500ms
  delay(500);
  tone(beeppin, 294);//Flat Re plays 500ms
  delay(500);
  tone(beeppin, 330);//Flat Mi plays 500ms
  delay(500);
  tone(beeppin, 349);//Flat Fa plays 500ms
  delay(500);
  tone(beeppin, 392);//Flat So plays 500ms
  delay(500);
  tone(beeppin, 440);//Flat La plays 500ms
  delay(500);
  tone(beeppin, 494);//Flat Si plays 500ms
  delay(500);
  noTone(beeppin);//Stop for 1s
  delay(1000);
}