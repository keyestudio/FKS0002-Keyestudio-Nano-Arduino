/*
  keyestudio Nano Inventor Starter Kit
  Project 17.2 Invasion Alarm
  http://www.keyestudio.com
*/
int pir = 4;		//Set PIR sensor pin to D4
int red_led = 5;	//Set red LED to pin D5
int buzz = 6;		//Set buzzer to pin D6
void setup() {
  // put your setup code here, to run once:
  pinMode(pir,INPUT);		//Set PIR pin to input mode 
  pinMode(red_led,OUTPUT);	//Set LED pin to output mode 
  pinMode(buzz,OUTPUT);		//Set buzzer pin to output mode 
}

void loop() {
  // put your main code here, to run repeatedly:
  int pir_val = digitalRead(pir);
  if(pir_val == 1){
    digitalWrite(red_led,HIGH);
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(red_led,LOW);
    digitalWrite(buzz,LOW);
  }
}