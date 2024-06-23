/**
 * Lee el estado de un botón.
 * 
 * @param boton El pin del botón que se va a leer.
 * @return Devuelve true si el botón está presionado, false si no lo está.
 */

#include "botones.h"

estados estado;

bool leer_boton(int16_t boton){
  if ( !digitalRead(boton) ){ 
    delaynb(30);
    return !digitalRead(boton);
  } else{
    return 0;
  }
}

void inicio(void){
  estado = BUTTON_UP;
}

void actualizar(int16_t boton){
  switch (estado){
  case BUTTON_UP:
    if (!digitalRead(boton)){
      estado = BUTTON_FALLING;
    }
    break;
  case BUTTON_DOWN:
    if (digitalRead(boton)){
      estado = BUTTON_RISING;
    }
    
    break;
  case BUTTON_FALLING:
    if (delaynb(40)){
      if (!digitalRead(boton)){
        estado = BUTTON_DOWN;
      } else{
        estado = BUTTON_UP;
      }     
    }
    break;
  case BUTTON_RISING:
    if (delaynb(40)){
      if (digitalRead(boton)){
        estado = BUTTON_UP;
      } else{
        estado = BUTTON_DOWN;
      }
    }   
    break;
  default:
    errores();
    break;
  }
}



void errores(void){
  estado = BUTTON_UP;
}

int16_t delaynb(int16_t t_delay){
  int16_t t_base =1;
  static int16_t count = 0;
  int16_t n_time = t_delay / t_base;
  if (count >= n_time){
    count = 0;
    return 1;
  } else{
    delay(t_base);
    count++;
    return 0;
  }

}