#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datos_juego.h"
#include "estructura.h"

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

static int longi(FILE * f);
void guardar(datos data){
FILE * f;
int i,j,k,l;
f=fopen("Juego.txt","w");
if(f==NULL)
    printf("ERROR");
else{
    fprintf(f,"%i-%i-%i\n",data.tam,data.n_barc,data.b_dist);
    for(i=0;i<data.b_dist;i++)
        fprintf(f,"%c-%i\n",data.barco[i].id,data.barco[i].num);
    for(i=0;i<2;i++){
        fprintf(f,"%i-",i+1);
        fputs(data.jug[i].nombre,f);
        fprintf(f,"-%i-%c-%i\n",data.jug[i].n_disp,data.jug[i].tp_disp,data.jug[i].ganad);
        for(j=0;j<2;j++){
            for(k=0;k<data.tam;k++){
                for(l=0;l<data.tam;l++)
                    fprintf(f,"%c ",data.jug[i].tablero[j][k][l]);
                fprintf(f,"\n");
            }
        }
    }
    printf("\n-----------------------------------------\n");
    printf("\nPartida guardada con exito\n");
    fclose(f);
}
}
void cargar(datos *data){
FILE *f;
int i,j,k,l,aux1;
f=fopen("Juego.txt","r");
if(f==NULL)
    printf("ERROR");
else{
    rewind(f);
    fscanf(f,"%i-%i-%i",&data->tam,&data->n_barc,&data->b_dist);
    fgetc(f);
    data->barco=(barco*)malloc(sizeof(barco)*data->b_dist);
    if(data->barco==NULL){
        printf("\nERROR\n");
        exit(1);
    }
    for(i=0;i<data->b_dist;i++){
        fscanf(f,"%c-%i",&data->barco[i].id,&data->barco[i].num);
        data->barco[i].tam=tamano(data->barco[i].id);
        fgetc(f);
    }
    for(i=0;i<2;i++){
        fscanf(f,"%i",&aux1);
        fgetc(f);
        fgets(data->jug[i].nombre,longi(f)+1,f);
        fscanf(f,"-%i-%c-%i",&data->jug[i].n_disp,&data->jug[i].tp_disp,&data->jug[i].ganad);
        fgetc(f);
        for(j=0;j<2;j++){
            data->jug[i].tablero[j]=(char**)malloc(sizeof(char*)*data->tam);
            if(data->jug[i].tablero[j]==NULL){
                printf("\nERROR\n");
                exit(1);
            }else{
                for(k=0;k<data->tam;k++){
                    data->jug[i].tablero[j][k]=(char*)malloc(sizeof(char)*data->tam);
                    if(data->jug[i].tablero[j][k]==NULL){
                        printf("\nERROR\n");
                        exit(1);
                    }
                }
            }
        }
        for(j=0;j<2;j++){
            for(k=0;k<data->tam;k++){
                for(l=0;l<data->tam;l++)
                    fscanf(f," %c",&data->jug[i].tablero[j][k][l]);
                fgetc(f);
            }
        }
    }
    data->flota=1;
    data->inicializado=1;
    printf("\n-----------------------------------------\n");
    printf("\nPartida cargada con exito\n");
    fclose(f);
}
}
void reiniciar(datos *data){
int i,j,k,l;
for(i=0;i<2;i++){
    data->jug[i].n_disp=0;
    data->jug[i].ganad=0;
    for(j=0;j<2;j++){
        for(k=0;k<data->tam;k++){
            for(l=0;l<data->tam;l++)
                data->jug[i].tablero[j][k][l]='-';
        }
    }
}
data->flota=0;
data->reinicio=1;
printf("\n-----------------------------------------\n");
printf("\nPartida reiniciada con exito\n");
}
//Precondicion: f enlazado a un fichero abierto de texto
//Postcondicon: devuelve la longitud de la cadena que se va a leer
static int longi(FILE * f){
int i=0;
char c;
long pos=ftell(f);
for(c=fgetc(f);c!='-';i++)
    c=fgetc(f);
fseek(f,pos,SEEK_SET);
return i;
}
