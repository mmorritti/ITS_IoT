void setup() {
  pinMode(6, OUTPUT);

}

void loop() {
  for(int i = 0; i < 255; i++){
    digitalWrite(6,i);
    delay(5);
  }

  for(int i = 255; i > 0; i--){
    digitalWrite(6,i);
    delay(5);
  }

  

}
