# **Project 2: Breathing Light**

### **1. Description**
Arduino breathing light utilizes on-board programmable PWM to output analog waveform. After powering on, LED brightness can be adjusted through duty cycle of the waveform to eventually realize a breathing light. 

In this way, ambient light can be simulated by changing LED brightness along with time. Also, breathing light can form a colorful mini light show to construct a tranquil and warm environment.

### **2. PWM Working Principle**
PWM controls analog output via digital means, which are able to adjust the duty cycle of the wave (a signal circularly shifting between high level and low level).

For Arduino, digital ports of voltage output are LOW and HIGH, which respectively correspond to 0V and 5V. 

Generally, we define LOW as 0 and HIGH as 1. Arduino will output 500 signals of 0 or 1 within 1s. If they are 500 "1", 5V will be output. Oppositely, if they are all 0, the output will be 0V. Or if they are 010101010101..., the average output will be 2.5V. In other words, output ratio of 0 and 1 affects the voltage value. Honestly, it differs from real continuous output, yet the more 0 and 1 signals are output per unit time, the more accurate the control will be. 

![img-20230225090854](media/img-20230225090854.png)

### **3. Wiring Diagram**

![](media/01.jpg)

### **4. Test Code**

We adopt "**for**" statement to increase a variable from 0 to 255, and we define the variable as PWM output (**analogWrite(pin, value)**). By the way, a delay time may reinforce the control of LED shining time. Next, we use another "for" statement to decrease it from 255 to 0 with also a delay time to control LED dimming process. 

As a result, a breathing light is complete. 

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 2 Star Breathing Light
  http://www.keyestudio.com
*/
int ledPin = 3; // Define LED as digital port 3
void setup () {
  pinMode (ledPin, OUTPUT); // Initialize LED to output mode
}
void loop () {
  for (int i = 0; i < 255; i++) {	//for loop statement
    analogWrite (ledPin, i); //led gradually lights up
    delay (10); // Delay 10ms
  }
  for (int i = 0; i < 255; i--) {
    analogWrite (ledPin, i); // led gradually goes off
    delay (10); // Delay 10ms
  }
}
```

### **5. Test Result**
After uploading the code, we can see the LED dims gradually rather than all of a sudden. It "breathes" evenly.

### **6. Code Explanation**

**for (int i = 0; i <= 255; i ++){ ... }** 
The variable changes from 0 to 255. 
**i++** means i automatically add 1 for each time until it fails to meet the condition of i <= 255. Otherwise, the code will execute in a loop for a total of 256 times. 

**for (int i = 255; i >= 0; i --){ ... }**
Similarly, **i- -** indicates i circularly reduce 1 for each time until it dissatisfies i>= 0. 

**analogWrite (Pin, value)** 
It is a function of pin analog output value. **Pin** is a PWM interface, and **value** is the output PWM value within range of 0~255.

But why does this analog value output on a digital pin?
Because we control the brightness of LED via PWM whose interfaces on the development board include digital ports D3, D5, D6, D9, D10 and D11. That is to say, LED is controlled only when signal terminal connects to one of these interfaces. 

In this experiment, we connect signal terminal to D3 pin. And we set up the range of 0~255 and a condition that, the less PWM is, the dimmer LED will be. 

Let's back to this code. We set PWM value of D3 to i, which gradually add 1 for each time from 0 to 255. A 10ms delay occurs after each increase, and LED slowly becomes brighter. 
However, when PWM equals 255, i starts to decrease one by one from 255 to 0 also with a 10ms delay for each time. Then LED becomes dimmer. 
Finally LED alternates between bright and dim, just like breathing.

If you want to cut its alternative duration, you can modify the code "delay()" in for()loop. The shorter the delay time is, the shorter the duration time will be. 

**i++** 
i automatically add 1 for each loop. 




For details, please refer to:
[https://www.arduino.cc/reference/en/]( https://www.arduino.cc/reference/en/)

