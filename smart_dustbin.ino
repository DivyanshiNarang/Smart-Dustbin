#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
long duration, dist, average;   
long aver[3];   //array for average
void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(100);
    // servo.detach(); 
} 

void measure() {  
  
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
// delayMicroseconds(15);
// digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}

void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;  
// servo.attach(servoPin);
if ( dist<50 ) {
//Change distance as per your need
  // servo.attach(servoPin);  
 servo.write(180);    
 delay(1000);   
//  servo.detach();
 
}
else
{
  // servo.attach(servoPin);      
  servo.write(0);    
  delay(1000);
  // servo.detach();
}
Serial.print(dist);
}