#include<stdio.h>
#include"estructura.h"
#include "Disparos.h"
#include"random.h"
#include "marcar_casillas.h"
//NOTACION: * agua; - vacío; T tocado; H hundido

//precondicion tablero inicializado
//postcondicion devuelve valores para coordenadas por puntero segun el tipo disparo elegido
int disparo(int num, datos *d){
int rep=0,ret,i;
static int ultcord_num[2],cord2_num[2],cord1_num[2],tipo_auto[2]={0,0};
static char ultcord_let[2],cord2_let[2],cord1_let[2];
if(d->reinicio==1){
    for(i=0;i<2;i++)
        tipo_auto[i]=0;
}
if(d->jug[num].tp_disp=='M'){
    do{
    printf("\nIntroduzca coordenada (p.ej A1): ");
    scanf("%c%i",&ultcord_let[num],&ultcord_num[num]);
    if(((int)ultcord_let[num]-64>d->tam)||((int)ultcord_let[num]-64<=0)||(ultcord_num[num]>d->tam)||(ultcord_num[num]<=0))
        printf("\nIntroduzca una coordenada valida\n");
    }while(((int)ultcord_let[num]-64>d->tam)||((int)ultcord_let[num]-64<=0)||(ultcord_num[num]>d->tam)||(ultcord_num[num]<=0));
    actu_tablero(d,(int)ultcord_let[num]-65,ultcord_num[num]-1,num);
}else{
    printf("\nPresione <ENTER> para disparar");
    fflush(stdin);
    getchar();
    switch(tipo_auto[num]){
    case 0:
        rand_cord(&ultcord_let[num],&ultcord_num[num],num,*d);
        actu_tablero(d,(int)ultcord_let[num]-65,ultcord_num[num]-1,num);
        if(d->jug[num].tablero[1][(int)ultcord_let[num]-65][ultcord_num[num]-1]=='T'){
            cord1_let[num]=ultcord_let[num];
            cord1_num[num]=ultcord_num[num];
            tipo_auto[num]=1;
        }
        break;
    case 1:
        ady_cord(&ultcord_let[num],&ultcord_num[num],cord1_let[num],cord1_num[num],num,*d);
        actu_tablero(d,(int)ultcord_let[num]-65,ultcord_num[num]-1,num);
        if(d->jug[num].tablero[1][(int)ultcord_let[num]-65][ultcord_num[num]-1]=='T'){
            cord2_let[num]=ultcord_let[num];
            cord2_num[num]=ultcord_num[num];
            tipo_auto[num]=2;
        }
        break;
    case 2:
        ret=dir_cord(cord1_let[num],cord1_num[num],cord2_let[num],cord2_num[num],&ultcord_let[num],&ultcord_num[num],num,*d);
        actu_tablero(d,(int)ultcord_let[num]-65,ultcord_num[num]-1,num);
        if(d->jug[num].tablero[1][(int)ultcord_let[num]-65][ultcord_num[num]-1]=='H')
            tipo_auto[num]=0;
        else if(d->jug[num].tablero[1][(int)ultcord_let[num]-65][ultcord_num[num]-1]=='T'){
            if(ret==1){
                cord1_let[num]=ultcord_let[num];
                cord1_num[num]=ultcord_num[num];
            }else{
                cord2_let[num]=ultcord_let[num];
                cord2_num[num]=ultcord_num[num];
            }
        }
        break;
    }
    printf("\nDisparaste a la coordenada %c%i\n",ultcord_let[num],ultcord_num[num]);
}
printf("\nResultado del disparo:\n");
    switch(d->jug[num].tablero[1][(int)ultcord_let[num]-65][ultcord_num[num]-1]){
        case '*':
            printf("Agua (no diste a ningun barco)\n\n");
            rep=0;
            break;
        case 'T':
            printf("Tocado (le has dado a un barco)\n\n");
            rep=1;
            break;
        case 'H':
            printf("Hundido (has hundido un barco)\n\n");
            d->jug[num].b_hund++;
            rep=1;
            break;
    }
d->jug[num].n_disp++;
return rep;
}




