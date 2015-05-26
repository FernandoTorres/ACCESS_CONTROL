/*
NOTAS
=====
Informacion sobre las versiones del proyecto van abajo (despues del codigo)
*/


#include "./IRremote.h"
#include "./IRremoteInt.h"

int RECV_PIN = 11;
int RELAY_PIN = 12;
int DELAY_TIME = 500;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode( RELAY_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    openDoor();
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void openDoor(){
  digitalWrite( RELAY_PIN, HIGH);
  delay( DELAY_TIME);
  digitalWrite( RELAY_PIN, LOW);
}

/*
Version 0.2 -- Stand alone
==========================
REF: http://www.instructables.com/id/Atmega-Standalone-Running-without-crystal-oscillat/
Para correr el codigo en el ATMega 328 directamente

En OSX hay que agregar el texto de boards.txt que se descarga del sitio a (C-C C-V al final del texto)
/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/boards.txt

En Wintendo falta probar en la carpeta de instalacion de Arduino (no sirve en la carpeta del sketch)

Version 0.1
===========
* El codigo original funciona bien con la prueba del LED en Arduino Uno y Pro Mini.
*/

