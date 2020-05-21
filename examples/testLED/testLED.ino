/*
 * ESPCS
 * Exal Serial Protocol Communication System for Arduino
 *
 * https://github.com/Axolito/ESPCS/
 *
 * (c) 2020 Axolito - https://github.com/Axolito
 *
 * license GNU AGPL v3.0
 * [en] https://www.gnu.org/licenses/agpl-3.0.html
 * [fr] https://www.gnu.org/licenses/agpl-3.0.en.html
 * 
 * This example file is used to switch the Arduino's integrated LED (pin 13) on and off.
 * To do this, simply send the "command" via the serial port:
 * 1,1; ==> to switch on the LED
 * 1,0; ==> to switch off the LED
 * 
 */


#include <ESPCS.h>

ESPCS example;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  example.refresh();

  if (example.readAddress() == 1 && example.readValue() == 1){
    digitalWrite(13,HIGH);
  }
  if (example.readAddress() == 1 && example.readValue() == 0){
    digitalWrite(13,LOW);
  }
}
