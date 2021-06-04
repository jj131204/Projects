
#include "UbidotsMicroESP8286.h"

#define TOKEN "•••••••••••••••••••••••••••••••••••"
#define WIFISSID "VALENCIA REPETIOR"
#define CONTRASEÑA "CONTRASEÑA"

Ubidots client(TOKEN)

void setup(){
  Serial.begin(115200);
  client.wifiConnection(WIFISSID,  CONTRASEÑA);
}

void loop(){
  float value = analogRead(A0);
  client.sendA11(true);
  delay(1000);
}
