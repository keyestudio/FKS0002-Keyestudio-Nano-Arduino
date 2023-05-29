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