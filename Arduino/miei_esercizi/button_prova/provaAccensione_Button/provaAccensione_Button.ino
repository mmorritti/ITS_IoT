
const int led = LED_BUILTIN;
const int button = 5; 
int buttonState = 0;


void setup(){
  pinMode(led,OUTPUT);
  pinMode(button, INPUT);

  
}

void loop(){
 
  
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  
  if(buttonState == 1){
    digitalWrite(led,LOW);
    delay(15); 
  }
  else{
    digitalWrite(led, HIGH);
    delay(15);  
  }
  
  
  
  
}
