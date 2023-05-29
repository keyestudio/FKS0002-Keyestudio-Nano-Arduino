# **Project 7：Buzzer**

### **1. Description**
An active buzzer can function as an alarm, a reminder or an entertaining device. It provides reliable voice warning for you.  What's more, it stimulates various sounds and features high controllability, so that you can experience an interesting and real experiment. 

### **2. Working Principle**

![image-20230317144940800](./media/image-20230317144940800.png)

**Working Principle:** 

An active buzzer integrates a multi-vibrator, so it makes sound only by a DC voltage. 

Pin 1 of the buzzer connects to VCC and pin 2 is controlled by a triode.  When a high level is provided for the base (pin 1) of the triode, its collector (pin 3) and emitter (pin 2) link to GND, and then the buzzer emits sound.  Oppositely, if we offer a low level to the base, the rest of pins will be disconnected, so the buzzer will remain quiet.

### **3. Wiring Diagram**

![05](media/05.jpg)

### **4. Test Code**

If the development board outputs a high level, the buzzer will emit sound. If it outputs a low level, the buzzer will stop ringing. 
Thus, its code is similar to light up an LED.

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 7 Buzzer
  http://www.keyestudio.com
*/
int buzzer = 3; //Define buzzer connecting to D3 pin
void setup() {
  pinMode(buzzer, OUTPUT);//Set the output mode
}

void loop() {
  digitalWrite(buzzer, HIGH); //D3 pin outputs a high level to cause the buzzer to emit sound
  delay(1000);	//Delay 1000ms
  digitalWrite(buzzer, LOW); //D3 pin outputs a low level to prevent the buzzer to emit sound
  delay(1000);
}
```

### **5. Test Result**

After uploading code and powering on, the buzzer emits sound for 1s and stays quiet for another 1s, in circulation. 



