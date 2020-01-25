#include <Wire.h>
float volt=0.0;
int rele=4;
void setup() {
Serial.begin(115200);
pinMode(rele, OUTPUT);
digitalWrite(rele, LOW);

}

void loop() {
volt= analogRead(0)*(5.0/1023.0);
volt=volt*5;
if(volt>8){
  digitalWrite(rele, HIGH);
}
else{
  digitalWrite(rele, LOW);
}
Serial.println(volt);
delay(500);
}
