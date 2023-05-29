/*
  keyestudio Nano Inventor Starter Kit
  Project 16 Timebomb
  http://www.keyestudio.com
*/
#include "KETM1650.h" //Upload TM1650 libraries
#include <LedControl.h>
//Dot matrix
int DIN = 11;     //Define DIN pin to D11
int CS =  10;     //Define CS pin to D10
int CLK = 13;     //Define CLK pin to D13

byte smile[8]=   {0x20,0x44,0x22,0x02,0x02,0x22,0x44,0x20};//Smile face  
byte weep[8]= {0x20,0x42,0x24,0x04,0x04,0x24,0x42,0x20};//Crying face

LedControl lc=LedControl(DIN,CLK,CS,4);  

// Button, buzzer and digital tube 
int item = 0; //the displayed value 
KETM1650 tm_4display(A5,A4);  //Set the interface to A5 and A4

int addition = 3;		//Set the plus button to D3
int subtraction = 4;	//Set the minus button to D4
int start = 5;			//Set the start button to D5
int reset = 6;			//Set the reset button to D6
int buzz = 2;			//Set the buzzer to D2

int buzz_val = 1;		//The variable of buzzer

void printByte(byte character [])  // The dot matrix display function
{  
  int i = 0;  
  for(i=0;i<8;i++)  
  {  
    lc.setRow(0,i,character[i]);  
  }  
} 

void setup(){
  lc.shutdown(0,false);       //MAX72XX is in power saving mode when starting   
  lc.setIntensity(0,8);       //Set the brightness to the maximum   
  lc.clearDisplay(0);         //Clear the display   
 //Set the pins mode  
  pinMode(addition,INPUT);		
  pinMode(subtraction,INPUT);
  pinMode(start,INPUT);
  pinMode(reset,INPUT);
  pinMode(buzz,OUTPUT);
  tm_4display.init(); // Initialization 
  tm_4display.setBrightness(3); //Set the brightness to 3, within the range of 1~8
}

void loop(){
  printByte(smile);		//Dot matrix displays a smile face 
  tm_4display.displayString(item);//Digital tube displays the item value 
  int blue_key = digitalRead(addition);		//Read the button value 
  int green_key = digitalRead(subtraction);
  int yellow_key = digitalRead(start);
  if(blue_key == 0){	//Determine whether the button is pressed 
    item = item + 1;  	// +1
    delay(200);
  }
  if(green_key == 0 ){
    item = item - 1;  // -1
    delay(200);
  }
  
  if (item > 9999) {  //When the value is greater than 9999(exceeding the display range), reset
    item = 0; 
  }
  if(yellow_key == 0){
    while(1){					//whlie()loop
      tm_4display.displayString(item);//Digital tube displays the item value
      item--;					//"item--" equals to "item = item - 1"
      delay(1000);
      buzz_val = !buzz_val;		//“！”, NOT gate. invert buzz_val
      digitalWrite(buzz,buzz_val);
      if(item == 0){
        digitalWrite(buzz,LOW);
        break;					//break the loop 
      
      }
    }
    while(item==0){				//when itme=0, enter loop 
      tm_4display.displayString(item);//Digital tube displays the item value
      printByte(weep);					//Display a crying face
      int red_key = digitalRead(reset);
      if(red_key == 0){
        break;
      }
    }
  }

}