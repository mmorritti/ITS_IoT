
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>


char auth[] = "UaG42ZA6GPObCA8wNlbhImT6LFtsSRQd"; //token ricevuto via mail

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "FASTWEB-E6QTGM"; //nome rete wifi 
char pass[] = "LMNLQAI0BP"; //password rete

BlynkTimer timer;

void setup()
{

  pinMode(5,INPUT);
  Serial.begin(9600); //inizializzazione seriale

  Blynk.begin(auth, ssid, pass); //prende come parametri il token, il nome e la pass
  timer.setInterval(300L,readBt);
  
}

void loop()
{
  Blynk.run(); //avvia blynk
  timer.run();

}

void readBt(){
  if(Blynk.digitalRead(V6)){
    digitalWrite(5,LOW);
  
  }else{
    digitalWrite(5,HIGH);
  }
}
