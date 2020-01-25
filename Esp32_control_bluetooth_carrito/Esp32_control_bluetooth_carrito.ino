#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
//#include <SoftwareSerial.h> 
const int ledPin=15;
const int ledPin2=2;
const int ledPin3=4;
const int ledPin4=16;
const int freq=5000;
const int ledChannel=0;
const int ledChannel2=1;
const int ledChannel3=2;
const int ledChannel4=3;
const int resolution=8;
//A=RUN
//B=RIGHT
//C=LEFT
//D=BACK
//E=AB
//F=AC
//G=DA
//H=DC
//P=STOP
int state = 0; // Variable lectrura dato serial
BluetoothSerial SerialBT;//bluetooth hc-05

void setup() {
   ledcSetup(ledChannel,freq,resolution);
   ledcSetup(ledChannel2,freq,resolution);
   ledcSetup(ledChannel3,freq,resolution);
   ledcSetup(ledChannel4,freq,resolution);
   ledcAttachPin(ledPin,ledChannel);
   ledcAttachPin(ledPin2,ledChannel2);
   ledcAttachPin(ledPin3,ledChannel3);
   ledcAttachPin(ledPin4,ledChannel4);
   //Serial.begin(115200); si se quiere escribir algo en monitor serial activar esta linea
   SerialBT.begin("CarritoBluetooth"); //Bluetooth device name

    
}
 
void loop() {
 
        if(SerialBT.available() > 0){
             state = SerialBT.read();
        } 
       
      //NIVEL DE FUERZA 2
       if (state == 'A' ) {
       
           ledcWrite(ledChannel, 255);//LLANTA DERECHA
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 255);//LANTA IZQUIERDA
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
        if (state == 'B' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
              if (state == 'C' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 63);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }

              if (state == 'D' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
              if (state == 'z' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
       

       if (state == 'F' ) {//TOTAL DE GIRO A LA DERECHA
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'G' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'H' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 63);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'J' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);          
           state = 0;
       }
              if (state == 'K' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);          
           state = 0;
       }

              if (state == 'L' )//ATRAS TOTAL
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 255);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
             if (state == 'Z' )
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
             if (state == 'X' )
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
             if (state == '|' )
       {
          ledcWrite(ledChannel, 63);
           ledcWrite(ledChannel2, 0);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
             if (state == 'V' )
       {
          ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }

       if (state == 'b') {//TOTAL GIRO IZQUIERDA
       
            ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
       if (state == 'N') {
       
            ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
       if (state == 'M') {
       
            ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);         
           state = 0;
       }

       if (state == 'Q') {
       
            ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 63);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
       if (state == 'W') {
       
            ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
//NIVEL DE FUERZA 1
       if (state == 'E' ) {
       
           ledcWrite(ledChannel, 127);//LLANTA DERECHA
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 127);//LANTA IZQUIERDA
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
        if (state == 'R' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 63);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
              if (state == 'T' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 31);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }

              if (state == 'Y' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 31);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
              if (state == 'U' )//GIRO A LA DERECHA
       {
            ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
       

       if (state == 'I' ) {//TOTAL DE GIRO A LA DERECHA
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 127);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'O' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 63);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'P' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 31);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == '0' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 31);          
           state = 0;
       }
              if (state == '1' ) {
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);          
           state = 0;
       }

              if (state == '2' )//ATRAS TOTAL
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 127);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
             if (state == '3' )
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
             if (state == '4' )
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 31);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
             if (state == '5' )
       {
          ledcWrite(ledChannel, 31);
           ledcWrite(ledChannel2, 0);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
             if (state == '6' )
       {
          ledcWrite(ledChannel, 63);
           ledcWrite(ledChannel2, 0);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }

       if (state == '7') {//TOTAL GIRO IZQUIERDA
       
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 127);         
           state = 0;
       }
       if (state == '8') {
       
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);         
           state = 0;
       }
       if (state == '9') {
       
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 31);         
           state = 0;
       }

       if (state == '+') {
       
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 31);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
       if (state == '¿') {
       
            ledcWrite(ledChannel, 127);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 63);
           ledcWrite(ledChannel4, 0);         
           state = 0;
       }
//nivel cero solo direcciones totale arriba abajo derecha iazquierda
       if (state == 'a' ) {
       
           ledcWrite(ledChannel, 63);//LLANTA DERECHA
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 63);//LANTA IZQUIERDA
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
              if (state == 'i' ) {//TOTAL DE GIRO A LA DERECHA
       
           ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
           ledcWrite(ledChannel3, 63);
           ledcWrite(ledChannel4, 0);          
           state = 0;
       }
                     if (state == 'd' )//ATRAS TOTAL
       {
          ledcWrite(ledChannel, 0);
           ledcWrite(ledChannel2, 63);
          ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);         
           state = 0;
       }

       if (state == 'h') {//TOTAL GIRO IZQUIERDA
       
            ledcWrite(ledChannel, 63);
           ledcWrite(ledChannel2, 0);
           ledcWrite(ledChannel3, 0);
           ledcWrite(ledChannel4, 63);         
           state = 0;
       }


     if (state =='p' )//PARAR
       {
           ledcWrite(ledChannel, 255);
           ledcWrite(ledChannel2, 255);
           ledcWrite(ledChannel3, 255);
           ledcWrite(ledChannel4, 255);         
           state = 0;
       }
}
