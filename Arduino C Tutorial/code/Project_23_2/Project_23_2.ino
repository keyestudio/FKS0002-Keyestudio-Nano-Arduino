/*
  keyestudio Nano Inventor Starter Kit
  Project 23.2 Smart Cup
  http://www.keyestudio.com
*/
#include <dht11.h>  
dht11 DHT;			//Define DHT example
#define DHT11_PIN 3 //Define DHT11_PIN to digital pin D3
int red_led =4;		//Define red_led to digital pin D4
int yellow_led = 5;	//Define yellow_led to digital pin D5
int green_led = 6;	//Define green_led to digital pin D6
int blue_led = 7; 	//Define blue_led to digital pin D7

void setup()
{
  pinMode(red_led,OUTPUT); 		//Set D4 pin to output
  pinMode(green_led,OUTPUT);	//Set D5 pin to output
  pinMode(blue_led,OUTPUT);		//Set D6 pin to output
  pinMode(yellow_led,OUTPUT);	//Set D7 pin to output
}
void loop()
{
  DHT.read(DHT11_PIN);    // Read the temperature and humidity value on pin D3
  int value = DHT.temperature;		// Assign the temperature and humidity value to the variable value
  if(value > 75){	//Determine whether value is greater than 75
    digitalWrite(green_led,LOW);
    digitalWrite(red_led,HIGH);
    digitalWrite(blue_led,LOW);
    digitalWrite(yellow_led,LOW);
  }
  if(value < 75 && value > 50){		//Determine whether value is between 50 and 75
    digitalWrite(green_led,LOW);
    digitalWrite(red_led,LOW);
    digitalWrite(blue_led,LOW);
    digitalWrite(yellow_led,HIGH);
  } 
  if(value < 50 && value > 25){		//Determine whether value is between 25 and 50
    digitalWrite(green_led,HIGH);
    digitalWrite(red_led,LOW);
    digitalWrite(blue_led,LOW);
    digitalWrite(yellow_led,LOW);
  }
  if(value < 25){					//Determine whether value is smaller than 25
    digitalWrite(green_led,LOW);
    digitalWrite(red_led,LOW);
    digitalWrite(blue_led,HIGH);
    digitalWrite(yellow_led,LOW);
  }
}