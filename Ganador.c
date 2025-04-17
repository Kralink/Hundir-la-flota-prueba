#include <stdio.h>
#include "Ganador.h"
#include "estructura.h"
void determinar_ganador(datos *partida, int resultado) { // la funcion lee la estructura y un resultado del 1 al 3
    int comienza; //si comienza es 0 comienza el jug 0 , si es 1 comienza jug 1.
    if(partida->jug[0].comienza==1)
    comienza=0;
    else
    comienza=1;
    if (resultado == 1)
        printf("El ganador es: %s\n", partida->jug[comienza].nombre); // es irrelevante que sea jug[0 o 2] por que abajo creo otro_jugador
    if (resultado == 2)
        printf("El ganador es: %s\n", partida->jug[1-comienza].nombre); // 1-0=1 y 1-1=0 entonces pilla el opuesto al que comienza
    if (resultado == 3)
        printf("Empate\n");
}
