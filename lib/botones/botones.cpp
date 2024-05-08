#include "botones.h"

bool leer_boton(int16_t boton){
  if ( !digitalRead(boton) ){ 
    delay(30);
    return !digitalRead(boton);
  } else{
    return 0;
  }
}