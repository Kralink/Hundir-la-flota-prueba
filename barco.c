#include<stdio.h>
#include "estructura.h"
#include "barco.h"
#include "random.h"

static int ady(char c,int n,datos d,int nj);

int barco_ubi(datos* data,int nj,char fil,int col,int dir,int i,char al){
int j,r=0;
    switch(dir){
    case 1:
        if (((int)fil-64 < data->barco[i].tam)||(col>data->tam - data->barco[i].tam +1)){
            if(al=='M')
            printf("ERROR: el barco no cabe");
            r=1;
        }else{
            for(j=0;(j<data->barco[i].tam)&&(r==0);j++){
                //for(k=fil-j-1;(k<=fil-j+1)&&(k>='A')&&(k<=(char)data->tam+64)&&(r==0);k++){//-j para que la fila vaya hacia arriba
                    //for(l=col+j-1;(l<=col+j+1)&&(l>=1)&&(l<=data->tam)&&(r==0);l++){//+ j para que la columna vaya hacia la derecha
                        if(ady(fil-j,col+j,*data,nj)==1){
                            if(al=='M')
                            printf("ERROR: el barco no cabe");
                            r=1;
                        }
                    //}
                //}
            }
        }
        if(r!=1){
            for(j=0;j<data->barco[i].tam;j++){
                data->jug[nj].tablero[0][(int)fil-65-j][col-1+j]=data->barco[i].id;
            }
        }
        break;
    case 2:
        if (((int)fil-64 > data->tam - data->barco[i].tam +1)||(col>data->tam - data->barco[i].tam +1)){
            if(al=='M')
            printf("ERROR: el barco no cabe");
            r=1;
        }else{
            for(j=0;(j<data->barco[i].tam)&&(r==0);j++){
                //for(k=fil+j-1;(k<=fil+j+1)&&(k>='A')&&(k<=(char)data->tam+64)&&(r==0);k++){//+j para que la fila vaya hacia abanjo
                    //for(l=col+j-1;(l<=col+j+1)&&(l>=1)&&(l<=data->tam)&&(r==0);l++){//+ j para que la columna vaya hacia la derecha
                        if(ady(fil+j,col+j,*data,nj)==1){
                            if(al=='M')
                            printf("ERROR: el barco no cabe");
                            r=1;
                        }
                    //}
                //}
            }
        }
        if(r!=1){
            for(j=0;j<data->barco[i].tam;j++){
                data->jug[nj].tablero[0][(int)fil-65+j][col-1+j]=data->barco[i].id;
            }
        }
        break;
    case 3:
        if (col>data->tam - data->barco[i].tam +1){
            if(al=='M')
            printf("ERROR: el barco no cabe");
            r=1;
        }else{
            for(j=0;(j<data->barco[i].tam)&&(r==0);j++){
                //for(l=col+j-1;(l<=col+j+1)&&(l>=1)&&(l<=data->tam)&&(r==0);l++){//+ j para que la columna vaya hacia la derecha
                    if(ady(fil,col+j,*data,nj)==1){
                        if(al=='M')
                        printf("ERROR: el barco no cabe");
                        r=1;
                    }
                //}
            }
        }
        if(r!=1){
            for(j=0;j<data->barco[i].tam;j++){
                data->jug[nj].tablero[0][(int)fil-65][col-1+j]=data->barco[i].id;
            }
        }
        break;
    case 4:
        if ((int)fil-64 > data->tam - data->barco[i].tam +1){
            if(al=='M')
            printf("ERROR: el barco no cabe");
            r=1;
        }else{
            for(j=0;(j<data->barco[i].tam)&&(r==0);j++){
                //for(k=fil+j-1;(k<=fil+j+1)&&(k>='A')&&(k<=(char)data->tam+64)&&(r==0);k++){//-j para que la fila vaya hacia arriba
                    if(ady(fil+j,col,*data,nj)==1){
                        if(al=='M')
                        printf("ERROR: el barco no cabe");
                        r=1;
                    }
                //}
            }
        }
        if(r!=1){
            for(j=0;j<data->barco[i].tam;j++){
                data->jug[nj].tablero[0][(int)fil-65+j][col-1]=data->barco[i].id;
            }
        }
        break;
    }
return r;
}

static int ady(char c,int n,datos d,int nj){
char i;
int j,r=0;
for(i=c-1;i<=c+1;i++){
    for(j=n-1;j<=n+1;j++){
        if((i>='A')&&(i<=(char)d.tam+64)&&(j>=1)&&(j<=d.tam)){
            if(d.jug[nj].tablero[0][(int)i-65][j-1]!='-')
            r=1;
        }
    }
}
return r;
}
