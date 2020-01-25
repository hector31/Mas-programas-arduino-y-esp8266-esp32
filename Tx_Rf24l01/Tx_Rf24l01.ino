/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//RF24 radio(7, 8); // CE, CSN pines para arduino normal
//Con NodeMcu en el D8 se debe utilizar un resistencia conectada a tierra de 4.75Kh
//coneccion NOodeMcu
//CSN ---------------- D8 es el GPIO 15
//MOSI --------------- D7
//MISO --------------- D6
//SCK ---------------- D5
//CE ------------------ D4 es el GPIO 2
RF24 radio(2, 15); // CE, CSN 
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}
void loop() {
  const char text[] = "Hola Mundo";
  radio.write(&text, sizeof(text));
  delay(1000);
}
