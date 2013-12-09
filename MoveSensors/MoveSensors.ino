
#include"acelerometro.h"

/*
  Programa que obtiene los datos del sensor
  de aceleraciones en tres ejes. También detecta caída libre con
  el pin fallAlarm. 
  El modo Sleep tampoco se implementa.
*/
//pines de Arduino de conexión
const int xpin=A0;  //acel. en x
const int ypin=A1;  //acel. en y
const int zpin=A2;  //acel. en z

const int fallAlarm=3;  //pin que escucha el 0g-Detect
const int fallLed=2;  //pin del LED que se enciende si cae
    
//enteros donde se guardaran los datos de aceleracion en volts
int voltX=0;
int voltY=0;
int voltZ=0;
    
//matriz con los valores de aceleracion en G`s
int xyz[3]={0,0,0};


void setup()
{

    //inicializamos el serial
    Serial.begin(9600);
    pinMode(fallLed, OUTPUT);
    //pinMode(gsel, OUTPUT);
    //pinMode(pinsleep, OUTPUT);
    pinMode(xpin, OUTPUT);
    pinMode(ypin, OUTPUT);
    pinMode(zpin, OUTPUT);
    pinMode(fallAlarm, INPUT);
}

void loop()
{
    //Leemos el pin de caida libre
    caida_libre=digitalRead(fallAlarm);
    //Leemos e imprimimos. De momento, es todo lo que haremos
    if(caida_libre==HIGH)      //comprueba si está cayendo
    {
        //Estaría bien implementar un zumbador, que tengo
        digitalWrite(fallLed, HIGH);
        delay(500);
        digitalWrite(fallLed, LOW);
    }
    
    else
    {
      //leemos los voltajes de cada eje
      voltX=analogRead(xpin);
      voltY=analogRead(ypin);
      voltZ=analogRead(zpin);
      Serial.print("Valor de X en mvolts: %d", &voltX);
      Serial.print();
      Serial.print("\nValor de Y en mvolts: %d", &voltY);
      Serial.print();
      Serial.print("\nValor de Z en mvolts: %d", &voltZ);
      Serial.print();
      Serial.print("--------------------------\n");
      Serial.print("--------------------------\n");
      delay(100);
      /*FALTA EL CÓDIGO QUE TRANSFORMA LOS VALORES DE mV EN ACELERACIÓN G*/
      xyz=VolttoG(voltX,voltY,voltZ);
      Serial.print("Valor de X: %d", xyz[0]);
      Serial.print();
      Serial.print("\nValor de Y: %d", xyz[1]);
      Serial.print();
      Serial.print("\nValor de Z: %d", xyz[2]);
      Serial.print();
      Serial.print("--------------------------\n");
      Serial.print("--------------------------\n");
    }
}
