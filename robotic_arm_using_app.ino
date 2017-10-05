#include<Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial bluetooth(12, 13);//tx,rx
Servo servox;
Servo servoy;
Servo servoz;
Servo servog;
int setspeed;

void arm(){
  servox.write(90);
  servoy.write(90);
  servoz.write(40);           //Writing Initial Position of Servo
  servog.write(0);
  delay(1000);
}
void setup() {
  // put your setup code here, to run once:
  

  servox.attach(9);
  servoy.attach(10);
  servoz.attach(11);          //Servos Interfacing Pins
  servog.attach(6);
  
 
  
  arm();
Serial.begin(9600);
bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bluetooth.available()>=2)
{
  unsigned int servopos = bluetooth.read();
  unsigned int servopos1 = bluetooth.read();
  unsigned int realservo = (servopos1 *256) + servopos;
  Serial.println(realservo);
  if(realservo>=1000 && realservo<1180){
    int servo1 = realservo;
    servo1=map(servo1,1000,1180,0,180);
    Serial.println(servo1);
   servox.write(servo1);
  }

  if(realservo>=2000 && realservo<2180){
    int servo1 = realservo;
    servo1=map(servo1,2000,2180,0,180);
    Serial.println(servo1);
   
    servoy.write(servo1);
    
  }


 if(realservo>=3000 && realservo<3180){
    int servo1 = realservo;
    servo1=map(servo1,3000,3180,0,180);
    Serial.println(servo1);
    servoz.write(servo1);
    
  }

  if(realservo>=4000 && realservo<4180){
    int servo1 = realservo;
    servo1=map(servo1,4000,4180,0,180);
    Serial.println(servo1);
    servog.write(servo1);
    
  }
}

}
