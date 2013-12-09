/****************************************************************
Aceler��metro.cpp. Implementaci��n de las funciones de biblioteca
del aceler��metro Arduino.

Proyecto creado con Code:Blocks Edici��n Arduino

Sensor MMA7361L de 3 ejes.

V��ctor Hevia Mart��n
20 de Octubre de 2013
Praga
*****************************************************************/

#include "acelerometro.h"

int* VolttoG(int voltX, int voltY, int voltZ)
{
  int resultado[3];
  //Chequea el valor de la sensibilidad
  if(gselect==0)
  {
    resultado[0]=voltX/800;
    resultado[1]=voltY/800;
    resultado[2]=voltZ/800;
  }
  /*else if(gselect==1)
  {
    x=voltX/600;
    y=voltY/600;
    z=voltZ/600;
  }*/
  return resultado;
}

/*Funci��n que cambia el modo de sensibilidad. Recibe la referencia a gselect ya que
* cambiaremos directamente este valor que ser�� el que usar�� VolttoG para saber
* cu��nto mide el cambio de mV del sensor.
*
* A IMPLEMENTAR: sobrecargar la funci��n de forma que acepte como argumento modo tanto el
* valor num��rico como un valor de texto.*/
/*void CambiarModo(byte &gselect, byte modo)
{

}*/
