
const int ledPin = 5;
const int buttonPin = 6;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW ;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;




void setup() {
  pinMode(ledPin, INPUT);
  pinMode(buttonPin,OUTPUT);
  digitalWrite(ledPin,ledState); //stato iniziale del led
  

}

void loop() {
  int reading = digitalRead(buttonPin);

  if(reading != lastButtonState){
    lastDebounceTime = millis(); //assegno a lastDebounce il tempo da cui è in esecuzione il programma
    
  }


  //sarà sempre maggiore
  if((millis() - lastDebounceTime) > debounceDelay){

    if(reading != buttonState){
      buttonState = reading;

      if(buttonState == HIGH){
        ledState = !ledState;
        
      }
    }
  }

  digitalWrite(ledPin,ledState);
  lastButtonState = reading;

  
  
}
