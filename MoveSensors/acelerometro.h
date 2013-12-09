/****************************************************************
Aceler��metro.h. Librer��a que define las variables un funciones de
uso del sensor de aceleraci��n para Arduino, dentro del proyecto
MoveSensors.

Proyecto creado con Code:Blocks Edici��n Arduino

Sensor MMA7361L de 3 ejes.

V��ctor Hevia Mart��n
20 de Octubre de 2013
Praga
*****************************************************************/
#ifndef ACELEROMETRO_H_INCLUDED
#define ACELEROMETRO_H_INCLUDED

#include <Arduino.h>

byte gselect=0;  //Cuando vale cero, rango de 1.5g y 800mV/g
                 //Si vale uno, rango de 6g y 206 mV/g
byte caida_libre=0;  //Detecta si esta en caida libre.

//Implementar Sleep-mode
//const int pinsleep=4;
//byte despierto=1;  //Si es 1, despierto. Si es cero, dormido

//Implementar Self Test

/*Chequea el valor de voltaje para convertirlo en un valor
de aceleraci��n real*/
int* VolttoG(int voltX, int voltY, int voltZ);
//void CambiarModo(byte &gselect);
#endif // ACELEROMETRO_H_INCLUDED
