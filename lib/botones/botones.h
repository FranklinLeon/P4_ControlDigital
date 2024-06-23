#ifndef __BOTONES_H__
#define __BOTONES_H__
#include <Arduino.h>

bool leer_boton (int16_t boton);

typedef enum{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_FALLING,
    BUTTON_RISING
} estados;

void inicio(void);
void actualizar(int16_t boton);
void errores(void);


int16_t delaynb(int16_t t_delay);

extern estados estado;


#endif // __BOTONES_H__