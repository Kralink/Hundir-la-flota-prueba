#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estructura.h"
#include "datos_juego.h"
void inicializar(datos *d);
void inicializar(datos *d) {
    // Inicializar los campos de 'datos' con 3
    /*d->tam = 3;
    d->n_barc = 3;
    d->b_dist = 3;
    d->inicializado = 3;*/

    // Inicializar los barcos
    d->barco = (barco *)malloc(3 * sizeof(barco)); // Asumimos que habrá 3 barcos
    /*for (int i = 0; i < 3; i++) {
        d->barco[i].id = 'a';  // Inicializar 'id' como 'a'
        d->barco[i].num = 3;   // Inicializar 'num' a 3
    }*/

    // Inicializar los jugadores
    for (int i = 0; i < 2; i++) {
        jugador *jug = &d->jug[i];

        /*jug->n_disp = 3;    // Inicializar 'n_disp' a 3
        jug->ganad = 3;       // Inicializar 'gan' a 3
        jug->tp_disp = 'r'; // Inicializar 'tp_disp' a 'a'

        // Inicializar 'nombre' a "hola"
        strncpy(jug->nombre, "hola", 25);*/

        // Inicializar el tablero de 2 matrices dinámicas 3x3
        for (int j = 0; j < 2; j++) {
            jug->tablero[j] = (char **)malloc(3 * sizeof(char *)); // Asignar 3 filas
            for (int k = 0; k < 3; k++) {
                jug->tablero[j][k] = (char *)malloc(3 * sizeof(char)); // Asignar 3 columnas
               /* for (int l = 0; l < 3; l++) {
                    jug->tablero[j][k][l] = 'a'; // Inicializar con 'a'
                }*/
            }
        }
    }
}

void liberar_memoria(datos *d) {
    // Liberar memoria para los barcos
    free(d->barco);

    // Liberar la memoria de los tableros de los jugadores
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                free(d->jug[i].tablero[j][k]); // Liberar cada fila
            }
            free(d->jug[i].tablero[j]); // Liberar cada matriz (fila)
        }
    }
}
int main(){
int a,b,r;
datos d;
d.inicializado=0;
srand(time(NULL));



printf("HUNDIR LA FLOTA\n(presiona enter)\n");
getchar();
do{
r=0;
do{
printf("\nMENU PRINCIPAL:\n1. Configuracion\n2. Jugar\n3. Salir\n(presiona el numero asociado)\n\n");
scanf("%i",&a);
if((a<1)||(a>3))
    printf("\nERROR: Introduzca un numero valido\n\n");
}while((a<1)||(a>3));
if(a!=3){
    switch(a){
    case 1:
        do{
        printf("\nCONFIGURACION:\n1. Introducir datos\n2. Mostrar\n3. Borrar\n4. Guardar\n5. Cargar\n6. Volver\n(presiona el numero asociado)\n\n");
        scanf("%i",&b);
        if((b<1)||(b>6))
        printf("\nERROR: Introduzca un numero valido\n\n");
        }while((b<1)||(b>6));
        if((d.inicializado==0)&&(b!=1)&&(b!=6))
            printf("\nPor favor introduzca primero la configuracion necesaria en el apartado Configuracion -> Introducir datos\n\n");
        else{
            switch(b){
            case 1:
                //Funcion
                break;
            case 2:
                //Funcion
                break;
            case 3:
                //Funcion
                break;
            case 4:
                guardar(d);
                break;
            case 5:
                cargar(&d);
                break;
            case 6:
                r=1;
                break;
            }
        }
    break;
    case 2:
        if(d.inicializado==0){
            printf("\nPor favor introduzca primero la configuracion necesaria en el apartado Configuracion -> Introducir datos\n\n");
            r=1;
        }else{
            do{
            printf("\nJUGAR:\n1. Jugar partida\n2. Reiniciar partida\n3. Resumen\n4. Volver\n(presiona el numero asociado)\n\n");
            scanf("%i",&b);
            if((b<1)||(b>4))
            printf("\nERROR: Introduzca un numero valido\n\n");
            }while((b<1)||(b>4));
            switch(b){
            case 1:
                //Funcion
                break;
            case 2:
                reiniciar(&d);
                break;
            case 3:
                //Funcion
                break;
            case 4:
                r=1;
                break;
            }
        }
    break;
    }
}
}while(r==1);
printf("\nGracias por jugar\n");
return 0;
}
