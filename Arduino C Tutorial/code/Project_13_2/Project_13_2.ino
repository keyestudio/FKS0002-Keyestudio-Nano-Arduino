/*
  keyestudio Nano Inventor Starter Kit
  Project 13.2 Mini Lamp
  http://www.keyestudio.com
*/
int button = 8;  //Define the variable button to pin D8
int LED = 3;	//Define LED to pin D3
int led_val = 0;
void setup() {
  pinMode(button, INPUT);  //Connect the button pin to digital port 8 and set it to the input mode
  pinMode(LED, OUTPUT);  //Connect LED pin to digital port 3 and set it to output mode
}

void loop() {
  int button_val = digitalRead(button);//Read the D8 pin button value
  if (button_val == 0) {  //Determine whether the button value equals 0
    led_val = !led_val;   //'!' takes the inverse sign, if it is 1, it becomes 0 or 0 becomes 1
    digitalWrite(LED, led_val); //Turn on LED or LED off
    while(!digitalRead(button)); //Preventing the inability to turn on the LED light due to prolonged button pressing
  }
}