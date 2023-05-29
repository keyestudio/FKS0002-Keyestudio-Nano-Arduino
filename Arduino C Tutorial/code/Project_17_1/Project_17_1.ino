/*
  keyestudio Nano Inventor Starter Kit
  Project 17.1 Invasion Alarm
  http://www.keyestudio.com
*/
int pir = 4;    //Define D4 pin to PIR sensor pin
void setup() {
  Serial.begin(9600);
  pinMode(pir,INPUT);   //Set D4 pin to input
}

void loop() {
  int pir_val = digitalRead(pir); 	//Read the PIR result and assign it to pir_val
    Serial.print("pir_val:"); //Print “pir_val”
	Serial.println(pir_val);
    delay(500);
}