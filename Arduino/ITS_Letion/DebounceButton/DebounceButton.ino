/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/


const int buttonPin = 6;    // numero pin bottone
const int ledPin = 5;      // numer pin led

// Variables will change:
int ledState = HIGH;         // stato corrente del pin in output
int buttonState;             // stato corrente del bottone in inpunt
int lastButtonState = LOW;   // la lettura precedente dal pin di input

// le seguenti variabili sono long senza segno perché il tempo, misurato in
// millisecondi, diventerà rapidamente un numero maggiore di quello che può essere memorizzato in un int.
unsigned long lastDebounceTime = 0;  // l'ultima volta che il pin di uscita è stato attivato
unsigned long debounceDelay = 50;    // il tempo di rimbalzo; aumenta se lo sfarfallio dell'output


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // imposta lo stato iniziale del LED
  digitalWrite(ledPin, ledState);
}

void loop() {
  // legge lo stato dello switch in una variabile locale:
  int reading = digitalRead(buttonPin);

  // controlla se hai appena premuto il pulsante
  // (ovvero l'ingresso è passato da BASSO a ALTO) e hai aspettato abbastanza a lungo
  // dall'ultima pressione per ignorare qualsiasi rumore:
   
  // Se l'interruttore è cambiato, a causa del rumore o premendo:
  if (reading != lastButtonState) {
    // resettare il timer di debouncing
    lastDebounceTime = millis(); 
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // qualunque sia la lettura, è lì da più tempo del rimbalzo
     // ritardo, quindi prendilo come lo stato attuale attuale:

    // se lo stato del pulsante è cambiato:
    if (reading != buttonState) {
      buttonState = reading;

     // attiva o disattiva il LED solo se il nuovo stato del pulsante è ALTO
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // setta il led
  digitalWrite(ledPin, ledState);

  // salva la lettura. La prossima volta attraverso il ciclo, sarà l'ultimoButtonState:
  lastButtonState = reading;
}
