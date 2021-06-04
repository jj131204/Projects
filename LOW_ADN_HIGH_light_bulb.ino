int Microfono=7; //MICROFONO EN PIN 7
int lecturaMicrofono=0; //GUARDAMOS LA LECTURA DEL MICROFONO PIN 8
int Rele=8; //RELE EN pin 8
int a=0; //BANDERA QUE CONTARA EL NUMERO DE APLAUSOS 
int b=0; //BANDERA PARA SALIR DE BUCLE

void setup(){ //CONFIGURACIONES GENERALES
  Serial.begin(9600); // COMUNICACION SERIAL
  pinMode(Microfono, INPUT); // MICROFONO COMO ENTRADA DE SEÑAL 
  pinMode (Rele,OUTPUT); //RELE COMO SALIDA DE SEÑAL
}

void loop(){ //PROGRAMA A EJECUTAR
  lecturaMicrofono=digitalRead (Microfono); //LEEMOS EL ESTADO QUE TIENE EL MICROFONO

  if (lecturaMicrofono==HIGH){ //SI TENEMOS UN APLAUSO?
    a=a+1;  // A=0+1=1 TENEMOS UN APLAUSO Y SEGUIRA AUMENTANDO CON CADA APLUSO 
    b=0;    //B=0 BANDERA PARA ENTRAR A BUCLES
    delay(200);
  }
  if(a==1 && b==0){ // SI TENEMOS 1 APLAUSO Y B=0 ENTONCES ENCENDEMOS EL FOCO
    Serial.println("ENCENDIDO");
    digitalWrite(Rele,HIGH);      //ENCENDEMOS FOCO
    b=1;                         //B=1 PARA SALIR DE BUCLE Y PODER CAMBIAR
  }

  if (a==2){       //SI TENEMOS 2 APALUSOS?
    Serial.println ("APAGADO"); //APAGAMOS
    digitalWrite(Rele,LOW);
    a=0;                       //REGRESAMOS EL CONTADOR A 0
   }
}
