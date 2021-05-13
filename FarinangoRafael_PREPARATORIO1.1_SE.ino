/*
 *PREPARATORIO I:COMUNICACION SERIAL Y TECLADO MATRICIAL
 *CODIGO I:Utilizar el teclado matricial dentro del entorno de Arduino, Codigo 10
 *NOMBRE:RAFAEL FARINANGO
 */

#include <LiquidCrystal.h> //importa librearia LiquidCrystal
#include <Keypad.h>     // importa libreria Keypad


LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto


void setup() {
  Serial.begin(9600);
}


void loop() {
  char a=teclado.getKey();
  if(a){
    Serial.print(a);
    if(a=='A' || a=='B' || a=='C' || a=='D'){
      Serial.println();
      Serial.println("Validado.!");
      }
    else{
      Serial.println();
      Serial.println("Error.!");
      }
    }
}
