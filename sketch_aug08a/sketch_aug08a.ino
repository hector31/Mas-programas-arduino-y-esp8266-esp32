/* 
 *  Bluetooh Basic: LED ON OFF - Avishkar
 *  Coder - Mayoogh Girish
 *  Website - http://bit.do/Avishkar
 *  Download the App : 
 *  This program lets you to control a LED on pin 13 of arduino using a bluetooth module
 */
 #include <Wire.h>
float volt=0.0;
int rele=4;
char Incoming_value = '0';                //Variable for storing Incoming_value
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);

}
void loop()
{
  volt= analogRead(0)*(5.0/1023.0);
  volt=volt*5;
  if(Serial.available() > 0)  
  {
   
    //Serial.println(volt);
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
//    Serial.println(Incoming_value);        //Print Value of Incoming_value in Serial monitor
//    //Serial.println("\n");        //New line 
//    
//    if(volt<8 && Incoming_value == '1')
//      digitalWrite(rele, LOW);
//
//    
//    delay(50);

  }
  Serial.println(Incoming_value);
//  else{
//     if(volt>8)
//      digitalWrite(rele, HIGH);
//     //Serial.println("hola");
//     
//     delay(50);
//  }
                              
 
}                 
