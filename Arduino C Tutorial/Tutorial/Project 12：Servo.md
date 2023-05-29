# **Project 12: Servo**

### **1. Description**
This servo features high performance and high precision with a maximum rotation angle of 180°. Weighting only 9g with a tiny size, it is perfectly suitable for any mini devices in any occasion. 

What's more, it enjoys short startup time, low noise and strong stability.

### **2. Working Principle**
**Angle Scale:** 180° (commonly 360°, 180° and 90°)

**Drive Voltage:** 3.3V / 5V

**Pin:** Three-wire

![wps1](media/wps1.png)

**GND:** Grounded, in brown

**VCC:** power supply pin connecting to +5v/3.3V, in red

**S:** Signal pin controlling PWM signal, in orange

![](./media/wps2(1)(1).png)

**Control Principle**: 

The rotation angle is controlled via duty cycle of PWM. 

Theoretically, standard PWM cycle is 20ms(50Hz), so pulse width should distribute within 1ms~2ms. However, the actual pulse width reaches 0.5ms~2.5ms, corresponding to 0°～180°. 

Pay attention that, for the same signal, the rotation angle vary from servo brands. 

### **3. Wiring Diagram**

![](./media/34(1).jpg)

### **4. Test Code**

Add libraries to Arduino IDE. If you skip this step, an error will occur when uploading and compiling the code.
For how to add libraries, please refer to “Development Environment Configuration”. 

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 12 Servo
  http://www.keyestudio.com
*/
#include <Servo.h>  //Servo library
Servo myservo;
void setup() {
  myservo.attach(9);//Set the control pin of servo to D9
}

void loop() {
  for (int pos = 0; pos < 180; pos++) {  //Control the servo to rotate from 0° to 180° by "for"loop.
    myservo.write(pos); //Rotate to angle of pos
    delay(15);  //Add a delay to slow the rotation
  }
  for (int pos = 180; pos > 0; pos--) {		//Control the servo to rotate from 180° to 0° by "for"loop.
    myservo.write(pos);
    delay(15);
  }
  delay(2000);//Wait 2s
}
```

### **5. Test Result**

After wiring up and uploading code, the servo starts to rotate from 0° to 180° and vice versa. 

### **6. Code Explanation**

**Servo myservo;**  Define an example of myservo

**myservo.attach(9);** Set the control pin of the servo

**myservo.write(pos);**  Set the rotation angle of the servo
