#include <stdio.h>
#include <stdlib.h>
#include "estructura.h"
#include "random.h"
#include "flota.h"
#include "barco.h"

static void mostrar_matriz(datos d, int nj, int n);

void flota(datos *data){
int col,dir,i,j,r,nj;
char fil,al;
printf("\n-----------------------------------------\n");
for(nj=0;nj<2;nj++){
    printf("\nTurno de %s de introducir su flota\n",data->jug[nj].nombre);
    do{
    printf("Como desea hacerlo?\nAleatoriamente(A)\nManualmente(M)\nRespuesta: ");
    fflush(stdin);
    al=getchar();
    if((al!='A')&&(al!='M'))
        printf("\nERROR: Introduce un numero valido\n\n");
    }while((al!='A')&&(al!='M'));
for(i=0;i<data->b_dist;i++){
    if(data->barco[i].num>1){
        for(j=0;j<data->barco[i].num;j++){
            do{
            r=0;
            if(al=='M'){
                printf("\n");
                mostrar_matriz(*data,nj,data->tam);
                printf("\n");
                do{
                    printf("\nPrimera coordenada del barco %c numero %i(p.ej A1): ",data->barco[i].id,j+1);
                    scanf(" %c%i",&fil,&col);
                    if(((int)fil-64>data->tam)||((int)fil-64<=0)||(col>data->tam)||(col<=0))
                        printf("\nIntroduzca una coordenada valida\n");
                }while(((int)fil-64>data->tam)||((int)fil-64<=0)||(col>data->tam)||(col<=0));
                do{
                    printf("En que direccion desea el barco %c numero %i(siendo la coma la primera coordenada)\n1. Diagonal 1 (,/)\n2. Diagonal 2 ('\\)\n3. Horizontal ('-)\n4. Vertical ('|)\n",data->barco[i].id,j+1);
                    scanf("%i",&dir);
                    if((dir<1)||(dir>4))
                        printf("\nIntroduce una direccion valida\n\n");
                }while((dir<1)||(dir>4));
            }else{
                rand_cord(&fil,&col,nj,*data);
                dir=(rand() % 4) + 1;
            }
            r=barco_ubi(data,nj,fil,col,dir,i,al);
            }while(r==1);
        }
    }else{
        do{
        r=0;
        if(al=='M'){
            printf("\n");
            mostrar_matriz(*data,nj,data->tam);
            printf("\n");
            do{
                printf("\nPrimera coordenada del barco %c numero %i(p.ej A1): ",data->barco[i].id,j+1);
                scanf(" %c%i",&fil,&col);
                if(((int)fil-64>data->tam)||((int)fil-64<=0)||(col>data->tam)||(col<=0))
                        printf("\nIntroduzca una coordenada valida\n");
            }while(((int)fil-64>data->tam)||((int)fil-64<=0)||(col>data->tam)||(col<=0));
            do{
                printf("En que direccion desea el barco %c numero %i(siendo la coma la primera coordenada)\n1. Diagonal 1 (,/)\n2. Diagonal 2 ('\\)\n3. Horizontal ('-)\n4. Vertical ('|)\n",data->barco[i].id,j+1);
                scanf("%i",&dir);
                if((dir<1)||(dir>4))
                    printf("\nIntroduce una direccion valida\n\n");
            }while((dir<1)||(dir>4));
        }else{
            rand_cord(&fil,&col,nj,*data);
            dir=(rand() % 4) + 1;
        }
        r=barco_ubi(data,nj,fil,col,dir,i,al);
        }while(r==1);
    }
}
printf("\nFlota de %s guardada con exito\n",data->jug[nj].nombre);
}
}

static void mostrar_matriz(datos d, int nj, int n){
int i,j;
printf("    ");
for(i=0;i<n;i++)
    if(i<=8)
        printf("%i   ",i+1);
    else
        printf("%i  ",i+1);
printf("         ");
for(i=0;i<n;i++){
    printf("\n\n");
    printf("%c   ",(char)i+65);
    for(j=0;j<n;j++)
            printf("%c   ",d.jug[nj].tablero[0][i][j]);
    printf("     ");
}
}

