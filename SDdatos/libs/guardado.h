#ifndef GUARDADO_H_INCLUDED
#define GUARDADO_H_INCLUDED
/**Libreria SDguardado
 *Autor: Victor Hevia
 *Projecto: Sonda HdC
 *Comentarios: esta librería se añadirá
 *en otros programas para guardar datos
 *de los sensores en tarjetas SD.
 *
 *Las funciones que contendrá serán de inicialización de la librería
 *así como diferentes funciones para formatear y guardar datos de
 *diferente tipo.
 *Para saber qué pines hay que dejar libres para trabajar co Arduino
 *y con la SD, este enlace contiene la información
 *C:\Programacion\Arduino\CodeBlocks*/
#include <SD.h>

//En las SD hay que dejar libre el pin SS que en la Arduino parece
//ser el 10. En la XBEE, que es la que contiene la tarjeta SD
//este es el pin 4 y de ahí el valor de esta constante
const int chip_select = 4;

/*Función de inicialización de los pines para la librería.
 *Se definirán también funciones para modificar los parámetros
 *de inicialización. pin10 representa el numero de pin 10, porque
 *en el ejemplo que usé usaban ese pin. De momento lo dejo tal
 *cuál porque sé que algunos pines hay que dejarlos libres para la SD.*/
 void iniciaSD(int pin10=10)
 {
     pinMode(pin10, OUTPUT);//TODO definir variables que sean las que definen el pin
     if(!SD.begin(chip_select)){
        Serial.println("Fallo al iniciar tarjeta SD...");
        return;
     }
     Serial.println("Tarjeta SD iniciada");
 }

#endif // GUARDADO_H_INCLUDED
