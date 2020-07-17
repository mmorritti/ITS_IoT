/*
  Example taken from Seeestudio Wiki
  adapted to work with Arduino Grove Carrier (on MKR1010)
  
  https://www.arduino.cc/en/Guide/MKRConnectorCarrier
  by Davide Gomba
*/

#include "Ultrasonic.h"

int pinLed = 5;
 
Ultrasonic ultrasonic(0);
void setup()
{
    Serial.begin(9600);
    pinMode(pinLed, OUTPUT);
}
void loop()
{
    long RangeInInches;
    long RangeInCentimeters;
 
   /* Serial.println("The distance to obstacles in front is: ");
    RangeInInches = ultrasonic.MeasureInInches();
    Serial.print(RangeInInches);//0~157 inches
    Serial.println(" inch");
    delay(250);
 */
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
   Serial.print(RangeInCentimeters);//0~400cm
    //Serial.println(" cm");
    float value = map(RangeInCentimeters, 10, 210, 255, 0);//map
    Serial.print(" - ");
    Serial.println(value);
    analogWrite(pinLed, value);
 
    delay(25);
}
