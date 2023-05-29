/*
  keyestudio Nano Inventor Starter Kit
  Project 29.2 IR Remote Control
  http://www.keyestudio.com
*/
#include <IRremote.h> //IR remote receiving library 
boolean flag = true;//LED flag bit 
long ir_rec;
int led_val = 0;

int led = 4;
IRrecv irrecv(3);
decode_results results;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);//connect LED pin to PWM port 5
  irrecv.enableIRIn();//Enable the IR Remote receiving 
}

void loop() {
  if (irrecv.decode(&results)) {//Receive signal
    ir_rec = results.value; //assign the signal to the variable ir_rec
    if(ir_rec != 0){        //Prevente the code from repeating execute when the button is pressed and held ，The meaning of "!=" not equal to
        Serial.print(ir_rec, HEX); //Print the variable ir_rec in hexadecimal
      if(ir_rec == 0xFF02FD){       //Determine whether the received IR signal is from button OK
        led_val = !led_val;           //Reverse a variable. If the initial value is 0, it turns to 1 after reversing, and vice versa. 
        digitalWrite(led,led_val);
      }
    }
    Serial.println();//wrap around to a new line
    irrecv.resume();//Receive next time 
  }
}