/*
  keyestudio Nano Inventor Starter Kit
  Project 29.1 IR Remote Control
  http://www.keyestudio.com
*/
#include <IRremote.h> //IR remote receiving library 
long ir_rec;
IRrecv irrecv(3);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();//Enable the IR Remote receiving 
}

void loop() {
  if (irrecv.decode(&results)) {//Receive signal 
    ir_rec = results.value; // assign the signal to the variable ir_rec
    if(ir_rec != 0){		//Prevente the code from repeating execute when the button is pressed and held ；The meaning of "!=" not equal to
    Serial.print(ir_rec, HEX); // Print the variable ir_rec in hexadecimal
    Serial.println();//wrap around to a new line
    }
    irrecv.resume();// Receive next time 
  }
}