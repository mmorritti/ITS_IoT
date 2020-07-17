void readSensor(){
  delay(2000);
  humidity = dht.readHumidity();
  // lettura celsius di default
  temperature = dht.readTemperature();
 
  // verificare che la lettura non fallisca
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(("Failed to read from DHT sensor!"));
    return;
  }
}

void oledInit(){
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    while(true);
  }
  
}

void setDisplay(){
  display.clearDisplay();
  display.setTextSize(1,2.5);//dimensioni testo
  display.setTextColor(WHITE);//colore testo
  display.cp437(true);//font
  display.setCursor(0,0);
}

String stampaTemp(){
 return  "Temperatura: \n" + (String)temperature + " Gradi ";  
}

String stampaHum(){
  return "Umidita: \n" + (String)humidity + "%";
}
