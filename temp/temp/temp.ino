#define SIGNAL_PIN 2
 
void setup()
{
Serial.begin(9600);
pinMode(SIGNAL_PIN, INPUT);
}
 
void loop() {
if(digitalRead(SIGNAL_PIN)==HIGH) {
Serial.println("Movement detected.");
} else {
Serial.println("Did not detect movement.");
}
delay(1000);
}
