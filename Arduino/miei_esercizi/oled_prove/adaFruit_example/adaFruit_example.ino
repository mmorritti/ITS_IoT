#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,4);


void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    while(true);
  }
  display.display();
  display.clearDisplay();
}

int x = 0;

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.cp437(true);

  display.setCursor(x,0);
  display.print("hello");
  display.display();
  delay(200);
  x+=3;
  if(x >= 128) x = 0;
  
}
