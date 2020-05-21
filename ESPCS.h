#ifndef ESPCS_h
#define ESPCS_h
    
#include <Arduino.h>
    
class ESPCS
{
public:
void refresh();
int readAddress();
int readValue();



private:
int _byte_read = 0;
int _separator = 44;//,
int _ender = 59;//;
int _index = 0;
int _n;
boolean is_a_number(int _n);
int ascii2int(int _n, int _byte_read);
int _adresse = 0;
int _valeur = 0;
};
    
#endif
