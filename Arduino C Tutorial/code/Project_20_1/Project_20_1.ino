/*
  keyestudio Nano Inventor Starter Kit
  Project 20.1 Light Pillar
  http://www.keyestudio.com
*/
int light = A0;
void setup(){  
 Serial.begin(9600); 
}  
  
void loop(){   
  int val = analogRead(light);
  Serial.println(val);
}  