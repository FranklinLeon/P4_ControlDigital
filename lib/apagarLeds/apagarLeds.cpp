/**
 * Apaga todos los LEDs en la secuencia de LEDs especificada en la estructura controlSecuencia.
 * 
 * @param controlador Puntero a una estructura controlSecuencia que contiene información sobre la secuencia de LEDs.
 * @return Devuelve un valor booleano indicando si todos los LEDs se apagaron correctamente.
 */

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