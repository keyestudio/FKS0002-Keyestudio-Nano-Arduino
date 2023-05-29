/*
  keyestudio Nano Inventor Starter Kit
  Project 20.2 Light Pillar
  http://www.keyestudio.com
*/
#include <LedControl.h>  
  
int DIN = 11;     //Defien DIN pin to D11
int CS =  10;     //Defien CS pin to D10
int CLK = 13;     //Defien CLK pin to D13
byte smile[8]=   {0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};//Smile face  
LedControl lc=LedControl(DIN,CLK,CS,4);  

void setup(){  
 lc.shutdown(0,false);       // MAX72XX is in power saving mode whrn starting   
 lc.setIntensity(0,1);       //Set the brightness to the maximum   
 lc.clearDisplay(0);         //Clear display  
 Serial.begin(9600); 
}  
  
void loop(){   
  int val = analogRead(A0);
  Serial.println(val);
  int temp = map(val,0,1023,0,7);
  lc.setRow(0,3,smile[temp]);
  lc.setRow(0,4,smile[temp]); 
  delay(500);//Delay 1s  
}  