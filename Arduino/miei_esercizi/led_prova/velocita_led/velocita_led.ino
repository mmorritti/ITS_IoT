void setup() {
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  int i = 700;
  while(i > 0){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(i);
    digitalWrite(LED_BUILTIN,LOW);
    delay(i);
    Serial.println(i);
    i-=10;
  }
  
  if(i == 0){
    while(i < 700){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(i);
      digitalWrite(LED_BUILTIN,LOW);
      delay(i);
      Serial.println(i);
      i+=10;
      
    }
  }
  

}
