
#include "DHT.h"

#define DHTPIN 2    

#define DHTTYPE DHT11   // DHT 11

// Inizializza il sensore DHT.
// Nota che le versioni precedenti di questa libreria hanno utilizzato un terzo parametro facoltativo
// modifica i tempi per processori più veloci. Questo parametro non è più necessario
// mentre l'attuale algoritmo di lettura DHT si adatta per lavorare su processi più veloci
DHT dht(DHTPIN, DHTTYPE);

float humidity;
float temperature;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  //aspetta due secondi per la misurazione
  delay(2000);
  readSensor(); 
  Serial.println(stampa());
 
}


void readSensor(){
  humidity = dht.readHumidity();
  // lettura celsius di default
   temperature = dht.readTemperature();
 
  // verificare che la lettura non fallisca
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(("Failed to read from DHT sensor!"));
    return;
  }
}

String stampa(){
 return "Umidità: " + (String)humidity + "% " + "Temperatura: " + (String)temperature + "°C ";  
}
