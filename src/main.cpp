#include <Arduino.h>
#include "botones.h"
#include "apagarLeds.h"
#include "secuenciaLeds.h"

const int16_t LED_VERDE = 2; 
const int16_t LED_AMARILLO = 3; 
const int16_t LED_ROJO = 4;
const int16_t LED_AZUL = 5; 
const int16_t SW1 = 6;
const int16_t SW2 = 7;
const int16_t SW3 = 8;
const int16_t SW4 = 9;


void setup(){
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(SW1, INPUT);
}

void loop(){
  // Variables para almacenar el estado anterior de los botones
  static bool prevSW3State = false;
  static bool prevSW4State = false;

  int16_t selector1 = 0;
  int16_t selector2 = 0;
  int16_t selector3 = 0;
  int16_t selector4 = 0;
  int16_t arregloLeds[] = {LED_VERDE, LED_AMARILLO, LED_ROJO, LED_AZUL};
  int16_t len = sizeof(arregloLeds) / sizeof(int16_t);
  int16_t tiempo = 500;
  enum sentido dir = derecha;
  controlSecuencia controlLeds = {arregloLeds, len, tiempo, dir};

  while(1){
    if (leer_boton( SW1 ) ){
      selector1 = !selector1;
      if ( selector1 ){
        controlLeds.dir = izquierda;
      } else{
        }
    }
    if (leer_boton( SW2 ) ){
      selector2= !selector2;
      if ( selector2 ){
        controlLeds.dir = derecha;
      } else{
        }
    }

    // Verificar el cambio de estado para SW3 y actualizar el tiempo si es necesario
    bool currentSW3State = leer_boton(SW3);
    if (currentSW3State != prevSW3State){
      selector3 = !selector3;
      if (selector3) {
        controlLeds.tiempo = 200;
      } else {
        controlLeds.tiempo = 500; // Si se desactiva SW3, volver al tiempo por defecto
      }
      prevSW3State = currentSW3State; // Actualizar el estado anterior
    }

    // Verificar el cambio de estado para SW4 y actualizar el tiempo si es necesario
    bool currentSW4State = leer_boton(SW4);
    if (currentSW4State != prevSW4State){
      selector4 = !selector4;
      if (selector4) {
        controlLeds.tiempo = 700;
      } else {
        controlLeds.tiempo = 500; // Si se desactiva SW4, volver al tiempo por defecto
      }
      prevSW4State = currentSW4State; // Actualizar el estado anterior
    }

    secuenciaLeds(&controlLeds); 
    delay(controlLeds.tiempo);
  }
}



