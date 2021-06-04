#include <Servo.h>

int led1=4;
int led2=6;
int led3=7;

Servo servoMotor;
void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);
  pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
}

void loop() {
  servoMotor.write(0);
  
  servoMotor.write(45); 
  delay(1000);
  
  servoMotor.write(90);
  delay(1000);
  
  servoMotor.write(135);
  delay(1000);
  
  servoMotor.write(180);
  delay(1000);
  
}
