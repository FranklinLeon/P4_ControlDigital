/**
 * Controla una secuencia de LEDs según la dirección especificada en la estructura controlSecuencia.
 * 
 * @param controlador Puntero a una estructura controlSecuencia que contiene información sobre la secuencia de LEDs.
 * @return Esta función no devuelve ningún valor explícito.
 */


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