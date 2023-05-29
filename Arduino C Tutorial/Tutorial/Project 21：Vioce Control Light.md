# **Project 21: Voice Control Light**

### **1. Description**
Voice control light module uses sound to control the brightness of LED. It can connect to other sensors, for example, microphone converts sound to changing voltage signal to be received by Arduino to control the LED on and off.

### **2. Working Principle**

![image-20230315150410153](./media/image-20230315150410153.png)

**Working Principle:** 
When detecting a sound, the electret film in microphone vibrates, which changes the capacitance and generates a subtle change of voltage. 
Next, we make use of LM358 chip to build a proper circuit to amplify , which can be adjusted by a potentiometer. Rotate it clockwise to enlarge the times. 

### **3. Wiring Diagram**

![21](./media/21.jpg)

### **4. Test Code**

Connect the sensor to pin A0. Read the sound analog value through analogRead(Pin) function and print it on serial monitor. 

```c
/*
  keyestudio Nano Inventor Starter Kit
  Project 21.1 Voice Control Light
  http://www.keyestudio.com
*/
int sound = A0;
void setup(){
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(sound);
  Serial.println(value);
}
```

### **5. Test Result**

After wiring up and uploading code, open serial monitor to set baud rate to 9600, the analog value will be displayed.

### **6. Expansion Code**

The commonly seen corridor light is a kind of voice control light. Meanwhile, it also includes a photoresistor. 

Differed from that, here we establish a model that an LED only is affected by voice. When the analog volume exceeds 100, LED lights up for 2S and then goes off. 

**Flow Diagram:**

![1679540516529-57](./media/1679540516529-57.png)

**Wiring Diagram:**

![22](./media/22-1679616502464-1.jpg)

**Code:**

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 21.2 Voice Control Light
  http://www.keyestudio.com
*/
int sound = A0;   //Define variable sound to pin A0
int led = 3;      //Define variable led to pin D3
void setup(){
  pinMode(led,OUTPUT);   //Set D3 pin to output 
}

void loop(){
  int value = analogRead(sound);    //Read analog value of A0 and assign it to value
  if(value > 100){                  //Determine whether value is greater than 100
    digitalWrite(led,HIGH);         //D3 pin outputs a high level, LED lights up
    delay(2000);
  }
  else{
    digitalWrite(led,LOW);          //D3 pin outputs a low level, LED goes off
  }
}
```

