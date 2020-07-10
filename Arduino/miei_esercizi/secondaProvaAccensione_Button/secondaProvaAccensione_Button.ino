
const int ledPin = LED_BUILTIN;
const int buttonPin = 5;
int buttonState = 0;
int ledState = 0;


void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == 1 && ledPin == LOW ) {
    digitalWrite(ledPin,HIGH);
    delay(15);
  }
 if(buttonState == 1 && ledPin == HIGH){
  digitalWrite(ledPin, LOW);
  delay(15);
 }
  

}
