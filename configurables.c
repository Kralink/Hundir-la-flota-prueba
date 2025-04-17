#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#include "configurables.h"

static int tamano(char id){
FILE *f;
int n=0,aux=0;
char c;
if((f=fopen("Barcos.txt","r"))==NULL)
    printf("ERROR");
else{
    rewind(f);
    while(((c=fgetc(f))!=EOF)&&(aux==0)){
        if(c=='-'){
            if(fgetc(f)==id){
                if(fgetc(f)=='-'){
                    fscanf(f,"%i",&n);
                    aux=1;
                }
            }
        }
    }
    fclose(f);
}
return n;
}

void introducir_datos(datos *data) {
    FILE * fp;
    int i,j,k,l,n,nb=1,aux=0;
    char c,d,id;
    printf("\n-----------------------------------------\n");
    for(i=0;i<2;i++){
        printf("\nIntroduce el nombre del jugador %i: ",i+1);
        scanf("%s",data->jug[i].nombre);
        do{
        printf("\nIntroduce tipo de disparo del jugador %i:\nAutomatico(A)\nManual(M)\nRespuesta: ",i+1);
        fflush(stdin);
        data->jug[i].tp_disp=getchar();
        }while((data->jug[i].tp_disp!='A')&&(data->jug[i].tp_disp!='M'));
        data->jug[i].n_disp=0;
        data->jug[i].ganad=0;
        data->jug[i].b_hund=0;
        data->flota=0;
        data->reinicio=0;
    }

    do{
    printf("\nIntroduce tamaño del tablero: ");
    scanf("%i", &data->tam);  // Guardar directamente en la estructura
    }while(data->tam<=0);
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if((data->jug[i].tablero[j]=(char**)malloc(sizeof(char*)*data->tam))==NULL){
                printf("ERROR");
            }else{
                for(k=0;k<data->tam;k++){
                    if((data->jug[i].tablero[j][k]=(char*)malloc(sizeof(char)*data->tam))==NULL){
                        printf("ERROR");
                    }else{
                        for(l=0;l<data->tam;l++)
                            data->jug[i].tablero[j][k][l]='-';
                    }
                }
            }
        }
    }

    printf("\nLista de barcos disponibles:\n");
    if((fp=fopen("Barcos.txt","r"))==NULL)
            printf("ERROR");
    else{
        char buffer[256];  // Buffer para leer cada línea
        while (fgets(buffer, sizeof(buffer), fp)){
            printf("%s", buffer);  // Escribe la línea en la salida estándar
        }
        rewind(fp);
        do{
            d=fgetc(fp);
            if(d=='\n')
                nb++;
        }while(d!=EOF);
        fclose(fp);
    }
    if((data->barco=(barco*)malloc(sizeof(barco)*nb))==NULL)
        printf("ERROR");
    else{
        do{
            printf("\nCuantos barcos se van a utilizar? ");
            scanf("%i",&data->n_barc);
            if((data->n_barc<=0)||(data->n_barc>(data->tam/2)))
                printf("\nERROR: Introduce un numero valido\n");
        }while((data->n_barc<=0)||(data->n_barc>(data->tam/2)));
        for(i=0,j=0;i<data->n_barc;i++){
            do{
                printf("\nID del barco %i(letra asociada): ",i+1);
                scanf(" %c",&id);
                if(tamano(id)==0)
                    printf("\nERROR: Barco inexistente\n");
                if(tamano(id)>data->tam)
                    printf("\nERROR: Tamaño del barco excesivo\n");
            }while((tamano(id)==0)||(tamano(id)>data->tam));
            aux=0;
            for(k=0;(k<nb)&&(aux==0);k++){
                if(data->barco[k].id==id){
                    data->barco[k].num++;
                    aux=1;
                }
            }
            if(aux==0){
                data->barco[j].id=id;
                data->barco[j].num=1;
                data->barco[j].tam=tamano(id);
                j++;
            }
        }
        data->b_dist=j;
    }

    do{
    printf("\nComo se elegirá el jugador que comienza la partida?\nPor consenso(C)\nAleatorio(A)\nRespuesta: ");
    fflush(stdin);
    c=getchar();
    }while((c!='A')&&(c!='a')&&(c!='C')&&(c!='c'));
    if((c=='A')||(c=='a')){
        int num=rand() % 2;
        if (num==0){
            printf("Empieza el jugador 1\n");
            data->jug[0].comienza=1;
            data->jug[1].comienza=0;
        }
        else{
            printf("Empieza el jugador 2\n");
            data->jug[1].comienza=1;
            data->jug[0].comienza=0;
        }
    }else{
        do{
        printf("Que jugador comienza la partida?(1 o 2): ");
        scanf("%i",&n);
        }while((n!=1)&&(n!=2));
        if(n==1){
            data->jug[0].comienza=1;
            data->jug[1].comienza=0;
        }else{
            data->jug[1].comienza=1;
            data->jug[0].comienza=0;
        }
    }
    printf("\nConfiguracion creada con exito\n");
    data->inicializado=1;
}

void mostrar_fichero(datos data){
    int i;
    printf("\n-----------------------------------------\n");
    for(i=0;i<2;i++){
        printf("\nNombre del jugador %i: %s\n",i+1,data.jug[i].nombre);
        printf("Tipo de disparo del jugador %i: %c\n",i+1,data.jug[i].tp_disp);
    }
    printf("Tamaño del tablero :%d\n\n",data.tam);
    for(i=0;i<data.b_dist;i++)
        printf("Tipo de barco %i:\nID: %c\nTamaño: %i\nNumero de barcos: %i\n\n",i+1,data.barco[i].id,data.barco[i].tam,data.barco[i].num);
    if (data.jug[0].comienza==1){
        printf("Empieza el jugador 1\n");
    }
    else{
        printf("Empieza el jugador 2\n");
    }
}

void borrar_datos (datos *data){
    int i,j,k;
    for(i=0;i<2;i++){
        memset(data->jug[i].nombre,0,sizeof(data->jug[0].nombre));
        data->jug[i].n_disp=0;
        data->jug[i].tp_disp=0;
        data->jug[i].comienza=0;
    }
    for(i=0;i<data->b_dist;i++){
        data->barco[i].id=0;
        data->barco[i].tam=0;
        data->barco[i].num=0;
    }
    data->tam=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<data->tam;k++){
                free(data->jug[i].tablero[j][k]);
            }
            free(data->jug[i].tablero[j]);
        }
    }
    printf("\n-----------------------------------------\n");
    printf("\nConfiguracion eliminada con exito\n");
    data->inicializado=0;
}
