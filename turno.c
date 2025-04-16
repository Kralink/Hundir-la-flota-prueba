#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"
#include "turno.h"
#include "Ganador.h"

static int recorrer_matriz(char**,int,datos);
static void mostrar_matriz(char**,int);

void turno(datos *d){
int com,gan,rep,i;
if(d->jug[0].comienza==1)
    com=0;
else
    com=1;
i=com;
do{
    printf("Turno de %s\n(presione enter cuando este listo)",d->jug[i].nombre);
    getchar();
    mostrar_matriz(d->jug[i].tablero[0], d->tam);
    printf("\n");
    mostrar_matriz(d->jug[i].tablero[1], d->tam);
    //disparo
    mostrar_matriz(d->jug[i].tablero[0], d->tam);
    printf("\n");
    mostrar_matriz(d->jug[i].tablero[1], d->tam);
    if(recorrer_matriz(d->jug[i].tablero[1],d->tam,*d)==1){
        if((i!=com)&&(gan==1)){
            gan=3; //Empate
            rep=0;
        }else if(i==com){
            gan=1; //Ganador 1
            rep=1;
        }else{
            gan=2; //Ganador 2
            rep=0;
        }
    }else if((i!=com)&&(gan==1))
        rep=0;
    else
        rep=1;
    i=(i-1)*(-1);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}while(rep==1);
determinar_ganador(d,gan);
}

static int recorrer_matriz(char **c, int n, datos d){
int i,j,h=0,nb=0,r;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(c[i][j]=='H')
            h++;
    }
}
for(i=0;i<d.b_dist;i++)
    nb+=(d.barco[i].num*d.barco[i].tam);
if(h==nb)
    r=1;
else
    r=0;
return r;
}

static void mostrar_matriz(char **c, int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        printf("%c ",c[i][j]);
    printf("\n");
}
}
