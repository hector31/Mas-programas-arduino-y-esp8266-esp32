#define triacPulse 5
int analogPin=A3;
int val=0;
int flag=0;
int tiempo2=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//pinMode(5,INPUT);
pinMode(3,OUTPUT);
pinMode(triacPulse, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(analogPin);
if(val==234){
  if(flag==0){
    flag=1;
    
  Serial.println(val);
  delayMicroseconds(tiempo2); // read AD1 
  digitalWrite(triacPulse, HIGH);
  delayMicroseconds(100);  
  digitalWrite(triacPulse, LOW);
  }
  else{
    flag=0;
  }
}
}
