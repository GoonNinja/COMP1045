// Adam Miszkiewicz
// working with servo motors

#include <Servo.h>
Servo myservo;
int btn1 = 2;
int btn2 = 3;
int val = 0;
int rgbled[] = {7, 6, 5};

void setup() {
  myservo.attach(4);
  myservo.write(0);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(rgbled[7, 5, 6], OUTPUT);
  Serial.begin(9600);
}

//function to cycle through the led on btn1 press
void btn1press()
{
   switch(val)
    {
     //val 1 will turn on green light
      case 1:
      analogWrite(rgbled[0], 255);
      break;
      //val 2 will turn off green and turn on blue
      case 2:
      analogWrite(rgbled[0], 0);
      analogWrite(rgbled[1], 255);
      break;
      //val 3 will turn off blue and turn on red
      case 3:
      analogWrite(rgbled[1], 0);
      analogWrite(rgbled[2], 255);
      break;
      //val 4 will turn on both red and blue to make purple
      case 4:
      analogWrite(rgbled[1], 255);
      analogWrite(rgbled[2], 255);
      break;
      //val 5 will cycle through all colours and return to original position
      case 5:
      analogWrite(rgbled[1], 0);
      analogWrite(rgbled[2], 0);
      delay(300);
      analogWrite(rgbled[0], 255);
      delay(300);
      analogWrite(rgbled[0], 0);
      delay(300);
      analogWrite(rgbled[1], 255);
      delay(300);
      analogWrite(rgbled[1], 0);
      delay(300);
      analogWrite(rgbled[2], 255);
      delay(300);
      analogWrite(rgbled[2], 0);
      delay(300);
      analogWrite(rgbled[1], 255);
      analogWrite(rgbled[2], 255);
      delay(300);
      analogWrite(rgbled[1], 0);
      analogWrite(rgbled[2], 0);
      myservo.write(0);
      val = 0;
    }
}

//funtion to cycle through lights on btn2 press
void btn2press()
{
  switch(val)
  {
    //val -1 will cycle through the colours and put servo in val 4
    case -1:
      analogWrite(rgbled[0], 255);
      delay(300);
      analogWrite(rgbled[0], 0);
      delay(300);
      analogWrite(rgbled[1], 255);
      delay(300);
      analogWrite(rgbled[1], 0);
      delay(300);
      analogWrite(rgbled[2], 255);
      delay(300);
      analogWrite(rgbled[2], 0);
      delay(300);
      analogWrite(rgbled[1], 255);
      analogWrite(rgbled[2], 255);
      myservo.write(180);
      val = 4;
      break;
    //val 0 will turn off green led
    case 0:
      analogWrite(rgbled[0], 0);
      break;
    //val 1 turns off blue led and turns green on
    case 1:
      analogWrite(rgbled[1], 0);
      analogWrite(rgbled[0], 255);
      break;
    //val 2 turns off red led and turns blue on
    case 2:
     analogWrite(rgbled[2], 0);
     analogWrite(rgbled[1], 255);
      break;
    //val 3 turns off blue led leaving only red on
    case 3:
      analogWrite(rgbled[1], 0);
      analogWrite(rgbled[2], 255);
      break;   
  }  
}

//main loop
void loop() 
{	
  if(digitalRead(btn1)== HIGH)
  {	
    val++;
    delay(100);
    Serial.println(val);
    btn1press();
  }

  
  if(digitalRead(btn2)== HIGH)
  {	
    val--;
    delay(100);
    Serial.println(val);
    btn2press();
  }
  
  delay(200);
  myservo.write(val*45);
  

}