#ifndef MARCAR_CASILLAS
#define MARCAR_CASILLAS

//precondicion tablero_flota inicializado con sus barcos y * en agua; tablero_disparos modificado con los disparos realizados; *x *y ultimas coordenadas disparadas
//postcondicion devuelve tablero actualizado de disparos del jugador correspondiente
void actu_tablero(datos *d,int x,int y,int num);

#endif // MARCAR_CASILLAS
