#ifndef __APAGARLEDS_H__
#define __APAGARLEDS_H__

#include "botones.h"

enum sentido {derecha, izquierda}; 

typedef struct{
  int16_t* leds;
  int16_t len;
  int16_t tiempo;
  enum sentido dir;
} controlSecuencia;

bool apagarLeds(controlSecuencia* controlador); 


#endif // __APAGARLEDS_H__