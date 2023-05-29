# **Project 17: Invasion Alarm**

### **1. Description**
This simple invasion alarm detects invaders in houses or small offices and warns the host to take measures in time. 

In this project, the sensor monitors a certain area. Some device on Arduino board will trigger LED to light up and buzzer to beep for caution if a movement is detected in that zone. 

Virtually, this module features practicability, simple-ness and low costs. With the exception of home and office, it also applies to factories, warehouses and markets, which, to a large extent, protects property security.

### **2. Working Principle**

![por](./media/por.png)

**Working Principle:** 
Human body(37°C) always emits infrared ray with a wavelength of 10μm or so, which approximates to that of the sensor detected. 
On this account, this module is able to detects human beings movement. If there is, PIR sensor outputs a high level about 3s . If not, it outputs a low level . 

### **3. Wiring Diagram**

![15](./media/15.jpg)

### **4. Test Code**

From the working principle, we read power level of the sensor pin to judge whether there is a human being. 

```c
/*
  keyestudio Nano Inventor Starter Kit
  Project 17.1 Invasion Alarm
  http://www.keyestudio.com
*/
int pir = 4;    //Define D4 pin to PIR sensor pin
void setup() {
  Serial.begin(9600);
  pinMode(pir,INPUT);   //Set D4 pin to input
}

void loop() {
  int pir_val = digitalRead(pir); 	//Read the PIR result and assign it to pir_val
    Serial.print("pir_val:"); //Print “pir_val”
	Serial.println(pir_val);
    delay(500);
}
```

### **5. Test Result**

After wiring up and upload code, open serial monitor to set baud rate to 9600, and the serial port prints the PIR value.

![image-20230410142533565](./media/image-20230410142533565.png)

### **6. Expansion Code**

In this expansion project, let's make an invasion alarm.  When the PIR sensor detects human, LED lights out and the buzzer emits sound. By contrast, LED goes off and the buzzer stays quiet. 

**Flow Diagram**:

![171717](./media/171717.png)

**Wiring Diagram**:

![16](./media/16.jpg)

**Code:**

To fulfil an invasion alarm, an "if() else" statement is necessary. 

```c
/*
  keyestudio Nano Inventor Starter Kit
  Project 17.2 Invasion Alarm
  http://www.keyestudio.com
*/
int pir = 4;		//Set PIR sensor pin to D4
int red_led = 5;	//Set red LED to pin D5
int buzz = 6;		//Set buzzer to pin D6
void setup() {
  // put your setup code here, to run once:
  pinMode(pir,INPUT);		//Set PIR pin to input mode 
  pinMode(red_led,OUTPUT);	//Set LED pin to output mode 
  pinMode(buzz,OUTPUT);		//Set buzzer pin to output mode 
}

void loop() {
  // put your main code here, to run repeatedly:
  int pir_val = digitalRead(pir);
  if(pir_val == 1){
    digitalWrite(red_led,HIGH);
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(red_led,LOW);
    digitalWrite(buzz,LOW);
  }
}
```



