
int TIEMPO = 50;
void setup() {
  pinMode(16, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(0, OUTPUT);    
  pinMode(2, OUTPUT);    
  pinMode(14, OUTPUT);    
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT);    
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(16, HIGH);   
  delay(TIEMPO);                     
  digitalWrite(16, LOW);  
   delay(TIEMPO);     

    digitalWrite(5, HIGH);   
   delay(TIEMPO);                     
  digitalWrite(5, LOW);  
   delay(TIEMPO);

    digitalWrite(4, HIGH);   
   delay(TIEMPO);                     
  digitalWrite(4, LOW);  
   delay(TIEMPO);

    digitalWrite(0, HIGH);   
   delay(TIEMPO);                    
  digitalWrite(0, LOW);  
   delay(TIEMPO);

      digitalWrite(2, HIGH);   
  delay(TIEMPO);                     
  digitalWrite(2, LOW);  
   delay(TIEMPO);

      digitalWrite(14, HIGH);   
   delay(TIEMPO);                    
  digitalWrite(14, LOW);  
  delay(TIEMPO);

       digitalWrite(12, HIGH);   
   delay(TIEMPO);                     
  digitalWrite(12, LOW);  
   delay(TIEMPO);

   digitalWrite(13, HIGH);   
   delay(TIEMPO);                     
  digitalWrite(13, LOW);  
   delay(TIEMPO);
}
