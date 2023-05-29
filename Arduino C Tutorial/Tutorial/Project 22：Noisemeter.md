# **Project 22: Noisemeter**

### **1. Description**
Arduino noisemeter detects and shows noise in an intriguing way. Iembodies the voice signal to a series of dots, which are converted into patterns displayed on dot matrix. 

### **2. Wiring Diagram**

![23](./media/23-1679536215604-22.jpg)

### **3. Test Code**

The noisemeter is able to detect the ambient noise. 

```C
/*
  keyestudio Nano Inventor Starter Kit
  Project 22 Noisemeter
  http://www.keyestudio.com
*/
#include <LedControl.h>  
  
int DIN = 11;     //Define DIN pin to D11
int CS =  10;     //Define CS pin to D10
int CLK = 13;     //Define CLK pin to D13 
int sensor = A0;

LedControl lc=LedControl(DIN,CLK,CS,4);  
byte data_val[][]= {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x01},
  {0x00, 0x00, 0x00, 0x00, 0x0f, 0x07, 0x03, 0x01},
  {0x00, 0x00, 0x00, 0x1f, 0x0f, 0x07, 0x03, 0x01},
  {0x00, 0x00, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01},
  {0x00, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01},
  {0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01}
  };


void setup(){  
 lc.shutdown(0,false);       //MAX72XX is in power saving mode when starting   
 lc.setIntensity(0,8);       //Set the brightness to the maximum  
 lc.clearDisplay(0);         //Clear display  
 Serial.begin(9600);
}  
  
void loop(){   
  int val = analogRead(sensor);
  Serial.println(val);
  int temp = map(val,0,700,0,7);
  for(int i=0;i<8;i++)  
  {  
    lc.setRow(0,7-i,data_val[temp][i]);  
  } 
}  
```

### **4. Test Code**

After wiring up and uploading code, the noise level view is displayed on dot matrix, as shown below.

![image-20230324092636680](./media/image-20230324092636680.png)            ![image-20230324092653930](./media/image-20230324092653930.png)       

### **5. Code Explanation**

**data_val[ ] [ ]{ … };** 
Two-dimensional array. If we use an axis X metaphor for linear array, two-dimensional array is axis X and Y. 
In this code, the value in the first square brackets is on axis X, and the second is on axis Y. For instance, column 3 row 4, that is data_val[ 3] [4 ]. 
