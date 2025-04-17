#ifndef RANDOM
#define RANDOM
#include "estructura.h"

//Precondición: *a >= 1 ; *c >= 'A' ; nj = 0 o 1 ; d inicializado
//Postcondicion: guarda en a y c un num y caracter aleatorios entre 1 y max y entre A y max, formando una coord
void rand_cord(char *c, int *a, int nj, datos d);

//Precondicion: *a >= 1 ; *c >= 'A' ; nj = 0 o 1 ; d inicializado
//Postcondicion: guarda en a y c un num y caracter aleatorios que formen una coord adyacente a la coordenada antes guardada en dichas variables
void ady_cord(char *l, int *nu, char c, int a, int nj, datos d);

int dir_cord(char let1, int num1, char let2, int num2, char *c, int *a, int nj, datos d);

#endif // RANDOM_H_INCLUDED
