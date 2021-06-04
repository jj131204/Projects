#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
int sensor;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  Serial.begin(9600);
  mp3_set_serial(Serial);
  mp3_set_volume(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = digitalRead(8);

  if(sensor == LOW){
    mp3_play(1);
    delay(8000);
  }
} 
