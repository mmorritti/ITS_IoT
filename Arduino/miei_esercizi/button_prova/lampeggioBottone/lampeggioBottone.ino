//Debounce button con lampeggiamento led

const int ledPin = 5;
const int buttonPin = 6;
int val = 0;
int oldVal = 0;
int buttonState;

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
 
}

void loop() {
  val = digitalRead(buttonPin);

  if((val == HIGH) && (oldVal == LOW)){
    buttonState = 1 - buttonState;
    delay(15);
  }

  oldVal = val;

  if(buttonState == 1){
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(500);
  }else{
    digitalWrite(ledPin,LOW);
  }

  
  
  

}
