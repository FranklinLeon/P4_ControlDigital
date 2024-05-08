#include "apagarLeds.h"
#include "secuenciaLeds.h"

bool secuenciaLeds(controlSecuencia* controlador) {
  static int16_t pos = 0;
  apagarLeds (controlador);
  digitalWrite(controlador->leds[pos], HIGH);
  if ( controlador->dir == derecha ){
    if ( pos < controlador->len - 1 ){
      ++pos;
    }else{
      pos = 0;
    }
  } else{
    if ( pos > 0 ){
      --pos;
    } else{
      pos = controlador->len - 1;
    }
  }
}