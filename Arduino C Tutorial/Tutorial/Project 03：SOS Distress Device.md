# **Project 3：SOS Distress Device**

### **1. Description**
Arduino SOS device is able to emit distress signals, which coincide with the principle of Morse code. It is convenient for emergencies.

### **2. Wiring Diagram**

![](media/01.jpg)

### **3. Test Code**

What we should clear firstly is how SOS distress light blinks: LED quickly blinks three times for “S” and slowly blinks three times for “O”. And then, we control the blinking times and duration via "for" statement and set interval time among letters. 

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 3 SOS Distress Device
  http://www.keyestudio.com
*/
int ledPin = 3;  //Define led to pin 3
 
void setup() {
pinMode(ledPin, OUTPUT);
}
 
void loop() {
// Three quick blinks mean an “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(150);                           //Delay 150ms
digitalWrite(ledPin,LOW);             //Set LED to turn off
delay(100);                           //Delay 100ms
}
 
//delay 200ms to generate the space between letters
delay(200);
 
//Three slow blinks mean an “O”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(400);                           //Delay 400ms
digitalWrite(ledPin,LOW);             //Set LED to turn off
delay(200);                           //Delay 200ms
}
 
//Delay 100ms to generate the space between letters
delay(100);
 
// Three quick blinks mean an “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(150);                           //Delay 150ms
digitalWrite(ledPin,LOW);             //Set LEDms
delay(100);                           //Delay 100ms
} 
// Wait 5s before repeating "S.0.S"
delay(5000);
}
```

### **4. Test Result**

After uploading the code, LED respectively blinks for 3 times in the sequence of quick, slow and quick, which forms "S.O.S". It repeats after 5s. 



