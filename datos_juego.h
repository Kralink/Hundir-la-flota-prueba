#ifndef DATOS_JUEGO
#define DATOS_JUEGO
#include "estructura.h"

//Precondicion: La estructura data esta inicializada con los datos de juego
//Postcondicion: Los datos de la estructura se escriben de forma ordenada en el fichero juegos.txt
void guardar(datos data);

//Precondicion: El fichero juegos.txt contiene toda los datos de juego
//Postcondicion: Los datos de juegos.txt se pasan a las variables respectivas de la estructura data
void cargar(datos *data);

//Precondicion: La estructura data esta inicializada con los datos de juego
//Postcondicion: Se reinician los tableros, el num de disparos de cada jugador y si son ganadores
void reiniciar(datos *data);

#endif // DATOS_JUEGO_H_INCLUDED
