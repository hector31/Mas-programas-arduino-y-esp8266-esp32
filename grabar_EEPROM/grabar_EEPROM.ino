#include <EEPROM.h>
int eepromcaja1= 1;
char valoresserial;
byte valorinicialeepromcaja1=0;
byte valor1=41;
byte valor2=86;

void setup() {
  Serial.begin(9600);
  Serial.println("Principio de programa");
  Serial.println("Comandos: 1- nos dice cual es el valor en la caja 1 de la EEPROM;2- no escribira en la caja 1 de la EEPROM el numero 41;3-Nos escribira en la caja 1 de la EEPROM el numero 86");
  EEPROM.write(eepromcaja1,valorinicialeepromcaja1);
}

void loop() {
 valoresserial= Serial.read();
 if(valoresserial == '1'){
    Serial.print("El valor en la caja 1 de la EEPROM es: ");
    Serial.println(EEPROM.read(eepromcaja1));
 }

 if(valoresserial=='2')
 {
  EEPROM.write(eepromcaja1,valor1);
  Serial.print("En la caja 1 de la EEPRM se escribio: ");
 Serial. println(valor1);
 }
 if(valoresserial== '3'){
  EEPROM.write(eepromcaja1,valor2);
  Serial.print("En la caja 1 de la EEPRM se escribio: ");
  Serial.println(valor2);
 }
}
