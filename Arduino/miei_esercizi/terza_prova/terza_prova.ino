int rispostaData = 0;

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.print("Ciao dalla tua scheda");
  Serial.println();
  Serial.print("Come ti chiami?");
  
  
}

void loop() {
  if(Serial.available() > 0){
    if(rispostaData == 0){
      String risposta = Serial.readString();
      Serial.print("Ciao "); Serial.print(risposta); Serial.print(" Piacere di conoscerti!");
      rispostaData = 1;
    }else{
      Serial.readString();
      Serial.println();
      Serial.print("Mi Hai già detto il tuo nome");
    }
  }

}
