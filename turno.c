#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"
#include "turno.h"
#include "Ganador.h"
#include "Disparos.h"

static int recorrer_matriz(char**,int,datos);
static void mostrar_matriz(datos,int,int);

void turno(datos *d){
char men;
int r,j;
static int com,gan,rep,i=-1,nrond=1;
if(d->reinicio==1){
    i=-1;
    nrond=1;
}
if(i==-1){
    if(d->jug[0].comienza==1)
        com=0;
    else
        com=1;
    i=com;
}
do{
    printf("\n-----------------------------------------\n");
    if(i==com){
        printf("\nRONDA NUMERO %i\n",nrond);
        printf("\n-----------------------------------------\n");
    }
    printf("\nTurno de %s\n(presione enter para comenzar turno o cualquier otra tecla para volver al menu)\n",d->jug[i].nombre);
    fflush(stdin);
    men=getchar();
    if(men=='\n'){
        if(i!=com)
            nrond++;
        printf("\nFLOTA");
        for(j=0;j<d->tam+1;j++)
            printf("    ");
        printf("OPONENTE\n");
        mostrar_matriz(*d,i,d->tam);
        printf("\n\n");
        do{
            r=disparo(i,d);
            printf("\nFLOTA");
            for(j=0;j<d->tam+1;j++)
                printf("    ");
            printf("OPONENTE\n");
            mostrar_matriz(*d,i,d->tam);
            printf("\n\n");
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
            if(r==1){
                if((gan==0)||((gan==1)&&(i!=com)))
                    printf("\nVuelves a disparar\n");
                else
                    r=0;
            }
        }while(r==1);
        printf("\nPresione <ENTER> para finalizar turno\n");
        fflush(stdin);
        getchar();

        i=(i-1)*(-1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}while((rep==1)&&(men=='\n'));
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

static void mostrar_matriz(datos d, int nj, int n){
int i,j,k;
printf("    ");
for(k=0;k<2;k++){
    for(i=0;i<n;i++)
        if(i<=8)
            printf("%i   ",i+1);
        else
            printf("%i  ",i+1);
    printf("         ");
}
for(i=0;i<n;i++){
    printf("\n\n");
    for(k=0;k<2;k++){
        printf("%c   ",(char)i+65);
        for(j=0;j<n;j++)
                printf("%c   ",d.jug[nj].tablero[k][i][j]);
        printf("     ");
}
}
}
