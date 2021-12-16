/*
 * ESPCS
 * Exal Serial Protocol Communication System for Arduino
 *
 * https://github.com/Axolito/ESPCS/
 *
 * (c) 2021 Axel BRUA (Axolito) - https://github.com/Axolito
 *
 * license GNU AGPL v3.0
 * [en] https://www.gnu.org/licenses/agpl-3.0.html
 * [fr] https://www.gnu.org/licenses/agpl-3.0.en.html
 * 
 */

#include <Arduino.h>
#include "ESPCS.h"

void ESPCS::refresh()
{
_adresse = 0;
_valeur = 0;
while ( Serial.available() > 0 ){      
    _byte_read = Serial.read();
    if (is_a_number(_byte_read) )
      {
        if (_index == 0){
          _adresse = ascii2int( _adresse, _byte_read );
        }
        
        if (_index == 1){
          _valeur = ascii2int( _valeur, _byte_read );
        }
        
      }
    else if ( _byte_read == _separator ){
      _index = 1;
      }
    else if ( _byte_read == _ender){
      _index = 0;
    }
}
delay (10);
}

int ESPCS::readAddress()
{
  return _adresse;
}

int ESPCS::readValue()
{
  return _valeur;
}

boolean ESPCS::is_a_number(int _n)
{
  return _n >= 48 && _n <= 57;
}


int ESPCS::ascii2int(int _n, int _byte_read)
{
  return _n*10 + (_byte_read - 48);
}
