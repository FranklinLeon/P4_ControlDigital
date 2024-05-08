/**
 * Lee el estado de un botón.
 * 
 * @param boton El pin del botón que se va a leer.
 * @return Devuelve true si el botón está presionado, false si no lo está.
 */

#include "botones.h"

bool leer_boton(int16_t boton){
  if ( !digitalRead(boton) ){ 
    delay(30);
    return !digitalRead(boton);
  } else{
    return 0;
  }
}