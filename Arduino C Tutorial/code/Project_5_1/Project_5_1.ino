/*
  keyestudio Nano Inventor Starter Kit
  Project 5  Rainbow Ambient Light
  http://www.keyestudio.com
*/
//Add 2812RGB library file
#include <NeoPixel.h>
Adafruit_NeoPixel  rgb_display(8);  //Define a class of pixels

void setup() {
  rgb_display.begin();  //Activate 6812RGB
  rgb_display.setPin(8);  //Set 2812 pin to digital port 8
  rgb_display.setBrightness(100); //Set the brightness to 100, within the range of 0~255
}

void loop() {
  rgb_display.setPixelColor(0, 255, 0, 0); //The frist pixel color is red
  rgb_display.setPixelColor(1, 0, 255, 0); //The second pixel color is green
  rgb_display.setPixelColor(2, 0, 0, 255); //The third pixel color is blue
  rgb_display.setPixelColor(3, 255, 255, 0); //The fourth pixel color is yellow
  rgb_display.setPixelColor(4, 255, 0, 255); //The fifth pixel color is purple
  rgb_display.setPixelColor(5, 255, 255, 255); //The sixth pixel color is white
  rgb_display.show(); //Display the pixel color
  delay(100);

}