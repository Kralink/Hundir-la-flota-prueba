#ifndef ESTRUCTURA
#define ESTRUCTURA

typedef struct{
char id;
int num, tam;
}barco;

typedef struct{
int n_disp, ganad, comienza, b_hund;
char nombre[25], tp_disp;
char **tablero[2]; //0:Flota---1:Oponente
}jugador;

typedef struct{
int tam, n_barc, b_dist, inicializado, flota, reinicio;
barco *barco;
jugador jug[2];
}datos;

#endif // ESTRUCTURA
