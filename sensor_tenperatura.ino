#include <LiquidCrystal.h>
LiquidCrystal lcd(7 ,6 ,5 ,4 ,3 ,2 );

int SENSOR;
float SUMA;
float TEMPERATURA;

//buzzer
float buzzer;
int sonido;

//led rgb
int pinR = 11;
int pinA = 10;
int pinV = 9;


void setup() {
  lcd.begin(16,2);
  //Serial.begin(96000)
  pinMode(8, OUTPUT);//buzzer
  //led rgb
  pinMode(pinR, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinV, OUTPUT);
}

void loop() {
  SUMA=0;
  for(int i=0; i<5; i++){
  SENSOR = analogRead(A0);
  TEMPERATURA = ((SENSOR + 5000.0) / 1023) / 10;
    SUMA = TEMPERATURA + SUMA;
      delay(100);
  }
  
  Serial.println(SUMA/5.0, 1);
  lcd.setCursor(0,0);
  lcd.print("temp: *");
  lcd.print(SUMA/5.0,1);
  lcd.print(" c")
    
    
    
 ;if(SUMA > 40){
    //buzzer
    for(int x=0; x<180; x++){
    //se convierte de grados a radianes 
      buzzer = (sin(x*(3.1412/180)));
      //se genera la fecuencia apartir del valor sin
      sonido = 2000 +(int(buzzer*1000));
      tone(8,sonido);
      
      
      //led rgb
      digitalWrite(pinR, OUTPUT);
      //analogoWrite(pinR,127);
      //analogoWrite(pinA,0);
      //analogoWrite(pinV,0);
      delay(1000);
    }
  }
  else if (SUMA >1   ){
  digitalWrite(pinV, OUTPUT);
   delay(1000);
  }
    else if (SUMA >1){
  digitalWrite(pinA, OUTPUT);
    delay(1000);
  }
}
