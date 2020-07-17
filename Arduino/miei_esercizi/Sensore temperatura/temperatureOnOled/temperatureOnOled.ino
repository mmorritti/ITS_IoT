#include "DHT.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,4);

#define DHTPIN 2    
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

float humidity;
float temperature;

void setup() {
  dht.begin();
  
}

void loop() {  
  readSensor();
  
 
  oledInit();
  setDisplay();
  display.print(stampaTemp());
  display.display();//scrive sul display il buffer
  delay(3000);
  display.clearDisplay();

  display.setCursor(0,0);
  
  display.print(stampaHum());
  display.display();
  delay(3000);
  display.clearDisplay();
  
 
  
  
  

}
