
#include "apagarLeds.h"

bool apagarLeds(controlSecuencia* controlador){
  int16_t aux = 1;
  for ( int16_t i = 0; i < controlador->len; ++i ){
    digitalWrite(controlador->leds[i], LOW);
    if ( digitalRead(controlador->leds[i]) == HIGH ){
      aux = 0;
    }
  }
  return aux;
}