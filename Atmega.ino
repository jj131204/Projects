#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(4 ,5 ,0 ,1 ,2 ,3);

int pin6 = 6; //Entrada 2 del L293D
int pin7 = 7; //Entrada 7 del L293D

int pin9 = 9; //Entrada 2 del L293D
int pin10 = 10; //Entrada 7 del L293D

int pin11 = 11; //Entrada 2 del L293D
int pin12 = 12; //Entrada 7 del L293D


/*int pinSC = 8; // DECLARACION DEL PIN 8 PARA EL SENSOR DE CARRERA*/



const byte ROWS = 4; // rows
const byte COLS = 3; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {A2, A3, A4, A5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A0, 13}; //connect to the column pinouts of the keypad

  char j[] = "0011";
    char z[] = "0000";
    char e[] = "1111";
   
  char codigo[4];                                     //arreglo donde almacenaremos la contraseña digitada
     
  int digito = 0;
  

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  /*pinMode(pinSC, INPUT); // DECLARACION DEL SENSOR EN TIPO ENTRADA*/
  /*Serial.begin(9600);*/
  //Inicializamos los pins de salida
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("INGRESE SU CLAVE");
}
/*int print_binary(unsigned long int n) // DE DECIMAL A BINARIO (RECURCION EN C++) O BIT A BIT 
{
 char count; 
        if (n > 1)
                return (print_binary(n >> 1));

        if ((n & 1) == 1)
                codigo[count] = 1;
        else
                codigo[count] = 0;
}
*/
void loop()
{

  char tecla = keypad.getKey();                   //guardamos el caracter de la tecla presionada en la variable tecla
  if (tecla != NO_KEY)                              //si "tecla" es diferente de "no tecla"... (si se presiona una tecla)
  { 
    codigo[digito] = tecla;                         //almacena en la posicion "digito" de "codigo" el caracter de la "tecla" presionada
    lcd.setCursor(5, 2);                   //se posiciona el cursor convenientemente
    lcd.print(codigo);                                 //se imprime "*" cada vez que se oprime una tecla
   digito = digito + 1;                              //incrementar la variable digito para almacenar los cuatro digitos presionados
      if (digito == 4){                                //si ya se llenaron los 4 digitos de codigo...
         if (codigo[0] == j[0] && codigo[1] == j[1] && codigo[2] == j[2] && codigo[3] == j[3]) //si el "codigo" digitado es igual a la "contraseña"
      {
           lcd.clear();
          analogWrite(pin9, 0);
          analogWrite(pin10, 140);
          lcd.setCursor(1,0);
          lcd.print("ABRIENDO P1");
          delay(500);
          analogWrite(pin9, 0);
          analogWrite(pin10, 0);
          lcd.setCursor(1,1);
          lcd.print("PUERTA ABIERTA");
          delay(500);
          lcd.clear();
          analogWrite(pin9, 140);
          analogWrite(pin10, 0);
          lcd.setCursor(1,0);
          lcd.print("CERRANDO P1");
          delay(500);
          analogWrite(pin9, 0);
          analogWrite(pin10, 0);
          lcd.setCursor(1,1);
          lcd.print("PUERTA CERRADA");
          delay(500);
          lcd.clear();
         digito = 0;
         for (int i=0; i<4; i++){
          codigo[i] = 0;
         }
         lcd.setCursor(0,0);
        lcd.print("INGRESE SU CLAVE");
      }

    
      else if (codigo[0] == z[0] && codigo[1] == z[1] && codigo[2] == z[2] && codigo[3] == z[3]) //si el "codigo" digitado es igual a la "contraseña"
      {
          lcd.clear();
          analogWrite(pin11, 0);
          analogWrite(pin12, 140);
          lcd.setCursor(1,0);
          lcd.print("ABRIENDO P2");
          delay(500);
          analogWrite(pin11, 0);
          analogWrite(pin12, 0);
          lcd.setCursor(1,1);
          lcd.print("PUERTA ABIERTA");
          delay(500);
          lcd.clear();
          analogWrite(pin11, 140);
          analogWrite(pin12, 0);
          lcd.setCursor(1,0);
          lcd.print("CERRANDO P2");
          delay(500);
          analogWrite(pin11, 0);
          analogWrite(pin12, 0);
          lcd.setCursor(1,1);
          lcd.print("PUERTA CERRADA");
          delay(500);
          lcd.clear();
         digito = 0;
         for (int i=0; i<4; i++){
          codigo[i] = 0;
         }
         lcd.setCursor(0,0);
        lcd.print("INGRESE SU CLAVE");
      }
  else if (codigo[0] == e[0] && codigo[1] == e[1] && codigo[2] == e[2] && codigo[3] == e[3]) //si el "codigo" digitado es igual a la "contraseña"
      {
        lcd.clear();
    analogWrite(pin6, 0);
    analogWrite(pin7, 140);
    lcd.setCursor(1,0);
    lcd.print("ABRIENDO P3");
    delay(500);
    analogWrite(pin6, 0);
    analogWrite(pin7, 0);
    lcd.setCursor(1,1);
    lcd.print("PUERTA ABIERTA");
    delay(500);
    analogWrite(pin6, 140);
    analogWrite(pin7, 0);
    lcd.setCursor(1,0);
    lcd.print("CERRANDO P3");
    delay(500);
    lcd.clear();
    analogWrite(pin6, 0);
    analogWrite(pin7, 0);
    lcd.setCursor(1,1);
    lcd.print("PUERTA CERRADA");
    delay(500);
    lcd.clear();
    digito = 0;
    for (int i=0; i<4; i++){
    codigo[i] = 0;
    }
    lcd.setCursor(0,0);
    lcd.print("INGRESE SU CLAVE");
    }
      
   else if (codigo != j || codigo != z || codigo != e ) //si el "codigo" digitado no es igual a la "contraseña"
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error, puerta no");
    lcd.setCursor(1,1);
    lcd.print("asociada con el codigo");
    delay(200);
    lcd.clear();
    digito = 0;
    for (int i=0; i<4; i++){
    codigo[i] = 0;
    }
    lcd.print("INGRESE SU CLAVE");
  }
  //Imprimo por el Serial Plotter
  }
 }
}
