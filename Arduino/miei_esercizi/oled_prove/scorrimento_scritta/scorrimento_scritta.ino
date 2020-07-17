#include <Arduino.h>
#include <U8g2lib.h>
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);//il primo parametro è l'inclinazione della scritta
 
void setup(void) {
  u8g2.begin();
}
 
void loop(void) {

  
  u8g2.clearBuffer();                   // cancella la memoria interna
  u8g2.setFont(u8g2_font_ncenB08_tr);   // scegli un carattere adatto


  for(int i = 0; i < u8g2.getDisplayWidth(); i++){
    u8g2.drawStr(0,10,"Ciao");
    u8g2.clearDisplay();
  }
  
  
  
  u8g2.sendBuffer();                    // trasferisc nello schermo
  
  delay(1000);  
}
