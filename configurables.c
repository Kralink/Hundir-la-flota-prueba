#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"

void introducir_datos(datos *data) {
    FILE * fp;
    int i,j,k,l,n,f,nb=1,nt=0;
    char c,d;
    printf("\n-----------------------------------------\n");
    for(i=0;i<2;i++){
        printf("\nIntroduce el nombre del jugador %i: ",i+1);
        scanf("%s",data->jug[i].nombre);
        do{
        printf("\nIntroduce tipo de disparo del jugador %i:\nAutomatico(A)\nManual(M)\nRespuesta: ",i+1);
        fflush(stdin);
        data->jug[i].tp_disp=getchar();
        }while((data->jug[i].tp_disp!='A')&&(data->jug[i].tp_disp!='M'));
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

    printf("\nDados los siguientes barcos:\n\n");
    if((fp=fopen("Barcos.txt","r"))==NULL){
            printf("ERROR");
    }
    char buffer[256];  // Buffer para leer cada línea
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);  // Escribe la línea en la salida estándar
    }
    rewind(fp);
    do{
        d=fgetc(fp);
        if(d=='\n')
            nb++;
    }while(d!=EOF);
    fclose(fp);
    do{
    printf("\nCuantos barcos de distinto tipo se van a utilizar?: ");
    scanf("%i",&f);
    }while((f<=0)||(f>nb));
    data->b_dist=f;
    if((data->barco=(barco*)malloc(sizeof(barco)*f))==NULL)
        printf("ERROR");
    else{
        for(i=0;i<f;i++){
            printf("\nID del tipo de barco %i (letra asociada): ",i+1);
            fflush(stdin);
            data->barco[i].id=getchar();
            do{
            printf("Tamaño del tipo de barco %i (numero asociado): ",i+1);
            scanf("%i",&data->barco[i].tam);
            if(data->barco[i].tam>(data->tam))
                printf("Seleccione un numero menor\n");
            }while((data->barco[i].tam<=0)||(data->barco[i].tam>(data->tam)));
            do{
            printf("Numero de barcos de este tipo que se desea añadir: ");
            scanf("%i",&data->barco[i].num);
            if(data->barco[i].num>=(data->tam-1))
                printf("Seleccione un numero menor\n");
            }while((data->barco[i].num<=0)||(data->barco[i].num>=(data->tam-1)));
            nt+=data->barco[i].num;
        }
        data->n_barc=nt;
    }

    do{
    printf("\nEscribe si se elige jugador por consenso(C) o aleatorio(A): ");
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
    printf("\n-----------------------------------------\n");
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
    printf("\n-----------------------------------------\n");
}

void borrar_datos (datos *data){
    int i,j,k;
    for(i=0;i<2;i++){
        memset(data->jug[i].nombre,0,sizeof(data->jug[0].nombre));
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
    data->inicializado=0;
}
