
const int tiempo = 3;
int flag_subida=0;
int flag_bajada=0;
int estado=0;
int ReleIzq=8;
int ReleDer=7;
int MosfetIzq=11;
int MosfetDer=10;
int subida=0,auxSubida=0;
int bajada=0,auxBajada=0;
int tiempoVelMax=0,auxMax=0;
int duty;
int porcentaje=0;
int i=0;
int basura=0;
int flagInversion=0;
int sentidoGiro=0;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(ReleIzq, OUTPUT);
  pinMode(ReleDer, OUTPUT);
  pinMode(MosfetIzq, OUTPUT);
  pinMode(MosfetDer, OUTPUT);
  digitalWrite(ReleIzq,HIGH);
  digitalWrite(ReleDer,HIGH);
  analogWrite(MosfetIzq,0);
  analogWrite(MosfetDer,0);
  
}

void loop() {
  // if there's any serial available, read it:
  switch(estado){
    case 0:
    Serial.println("Menu ingrese sentido de giro: \n");
    Serial.println("1-Horario \n");
    Serial.println("2-Antiohorario \n");
    estado=1;
    break;
    
    case 1:    
    while (Serial.available() > 0) {
    sentidoGiro = Serial.parseInt();
    if(sentidoGiro==1||sentidoGiro==2){
    Serial.println(sentidoGiro);     
    estado=2;
    basura = Serial.parseInt();
    break;
    }
    else{
    Serial.println("Error numero ingresado no identificado, ingrese nuevamente.\n");
      estado=0;
    }
    }
    break;

    case 2:
    Serial.println("Ingrese tiempo de subida \n");
    estado=3;
    break;
    
    case 3:
     while (Serial.available() > 0) {
    subida = Serial.parseInt();
    if(subida>3){
    Serial.println(subida);  
    auxSubida=subida;   
    estado=4;
    basura = Serial.parseInt();
    break;}
    
    else{
    Serial.println("Error ingresee un tiempo de subida mayor 3 segundos");
    estado=2;     
    }
     }
    break;
    //***************************
    case 4:
    Serial.println("Ingrese tiempo en maxima velocidad \n");
    estado=5;
    break;
    
    case 5:
     while (Serial.available() > 0) {
    tiempoVelMax = Serial.parseInt();
    if(tiempoVelMax>3){
    Serial.println(tiempoVelMax);  
    auxMax=tiempoVelMax;   
    estado=6;
    basura = Serial.parseInt();
    break;}
    
    else{
    Serial.println("Error ingresee un tiempo de subida mayor 3 segundos");
    estado=4;     
    }
     }
    break;
    //********************************
   
    case 6:
    Serial.println("Ingrese tiempo de bajada \n");
    estado=7;
    break;
    
    case 7:
    while (Serial.available() > 0) {
    bajada = Serial.parseInt();
    if(bajada>3){
    Serial.println(bajada);     
    auxBajada=bajada;
    estado=8;
    basura = Serial.parseInt();
    break;
    }
    else{
    Serial.println("Error ingresee un tiempo de bajada mayor 3 segundos");
    estado=6;     
    }
    }
    break;
    
    case 8:
     Serial.println("datos:\n");  
     Serial.println(sentidoGiro);  
     Serial.println(auxSubida);  
     Serial.println(auxBajada);  
     if(sentidoGiro==1){
      digitalWrite(ReleDer,LOW);
      for(i=0;i<=auxSubida;i++){
      duty=map(i,0,auxSubida,0,255);
      analogWrite(MosfetDer,duty);
      porcentaje=map(i,0,auxSubida,0,100);
      Serial.print(porcentaje);
      Serial.println("%");
      delay(1000);
      }
     }
       if(sentidoGiro==2){
      digitalWrite(ReleIzq,LOW);
      for(i=0;i<=auxSubida;i++){
      duty=map(i,0,auxSubida,0,255);
      analogWrite(MosfetIzq,duty);
      porcentaje=map(i,0,auxSubida,0,100);
      Serial.print(porcentaje);
      Serial.println("%");
      delay(1000);
      }    
      }
     Serial.println("Valor maximo alcanzado motor.");
      delay(1000*tiempoVelMax);
      estado=9;
    break;  
    
    case 9:
    if(sentidoGiro==1){
    for(i=0;i<=auxBajada;i++){
      duty=map(i,auxBajada,0,0,255);
      porcentaje=map(i,auxBajada,0,0,100);
      Serial.print(porcentaje);
      Serial.println("%");
      analogWrite(MosfetDer,duty);
      delay(1000);
      }
    }
    if(sentidoGiro==2){
    for(i=0;i<=auxBajada;i++){
      duty=map(i,auxBajada,0,0,255);
      porcentaje=map(i,auxBajada,0,0,100);
      Serial.print(porcentaje);
      Serial.println("%");
      analogWrite(MosfetIzq,duty);
      delay(1000);
      }
    }
    if(flagInversion==0){
      if(sentidoGiro==1)
        sentidoGiro=2;
      else
        sentidoGiro=1;
    estado=8; 
    flagInversion=1;       
    }
    else{
    estado=0; 
    flagInversion=0;}
    digitalWrite(ReleIzq,HIGH);
    digitalWrite(ReleDer,HIGH);
    break;
    
  }
    
  
 
 
}
