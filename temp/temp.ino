//#define DEBUG(a) Serial.println(a);

int valor=0;
void setup() {
  Serial.begin(9600);
    
}

void loop() {
  if(Serial.available()>0){
    String str=Serial.readStringUntil('\n');
    int data2=str.toInt();//IMPRIME DATOS
    //Serial.println(data2);
    }
    
  }
