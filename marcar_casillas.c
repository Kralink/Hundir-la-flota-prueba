#include<stdio.h>
#include "estructura.h"
#include "marcar_casillas.h"


static int ady_cas(datos d,int x,int y,int nj){
int i,j,aux=0,dir,n=0;
for(i=x-1;(i<=x+1)&&(aux==0);i++){
    for(j=y-1;(j<=y+1)&&(aux==0);j++){
        if((i>=0)&&(i<d.tam)&&(j>=0)&&(j<d.tam)&&((i!=x)||(j!=y))){
            if(d.jug[nj].tablero[1][i][j]=='T')
                aux=1;
        }
    }
}
i--;
j--;
if(((x-i)*(y-j))>0)
    dir=1; //(\)
else if(((x-i)*(y-j))<0)
    dir=2; //(/)
else{
    if((y-j)==0)
        dir=3; //(|)
    else
        dir=4; //(-)
}
aux=0;
switch(dir){
case 1:
    for(i=x,j=y;aux==0;i--,j--){
        if((i<0)||(j<0))
            aux=1;
        else if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
    }
    i=i+2;
    j=j+2;
    aux=0;
    while((aux==0)&&(i<d.tam)&&(j<d.tam)){
        if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
        else{
            n++;
            j++;
            i++;
        }
    }
    break;
case 2:
    for(i=x,j=y;aux==0;i++,j--){
        if((i>=d.tam)||(j<0))
            aux=1;
        else if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
    }
    i=i-2;
    j=j+2;
    aux=0;
    while((aux==0)&&(i>=0)&&(j<d.tam)){
        if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
        else{
            n++;
            j++;
            i--;
        }
    }
    break;
case 3:
    j=y;
    for(i=x;aux==0;i--){
        if(i<0)
            aux=1;
        else if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
    }
    i=i+2;
    aux=0;
    while((aux==0)&&(i<d.tam)){
        if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
        else{
            n++;
            i++;
        }
    }
    break;
case 4:
    i=x;
    for(j=y;aux==0;j--){
        if(j<0)
            aux=1;
        else if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
    }
    j=j+2;
    aux=0;
    while((aux==0)&&(j<d.tam)){
        if(d.jug[nj].tablero[1][i][j]!='T')
            aux=1;
        else{
            n++;
            j++;
        }
    }
    break;
}
return n;
}

static int hundido(datos *d,int nj){
int i,j,k,l,n=0,aux=0;
for(i=0;i<d->tam;i++){
    for(j=0;j<d->tam;j++){
        if(d->jug[nj].tablero[1][i][j]=='H'){
            for(k=i-1;(k<=i+1)&&(aux==0);k++){
                for(l=j-1;(l<=j+1)&&(aux==0);l++){
                    if((k>=0)&&(k<d->tam)&&(l>=0)&&(l<d->tam)){
                        if(d->jug[nj].tablero[1][k][l]=='-')
                            d->jug[nj].tablero[1][k][l]='*';
                        else if(d->jug[nj].tablero[1][k][l]=='T'){
                            n=1;
                            d->jug[nj].tablero[1][k][l]='H';
                        }
                    }
                }
            }
        }
    }
}
return n;
}

//precondicion inicializados coordenadas(x,y) y la estructura datos con los tableros
//postcondicion actualiza tablero_disparos en la coordenada (*x,*y) dependiendo de su resultado con -,T o H
void actu_tablero(datos *d,int x,int y,int num){
int i,tp,n;
if(d->jug[1-num].tablero[0][x][y]=='-')
    d->jug[num].tablero[1][x][y]='*';
else{
    d->jug[num].tablero[1][x][y]='T';
    for(i=0;i<d->b_dist;i++){
        if(d->jug[1-num].tablero[0][x][y]==d->barco[i].id)
            tp=i;
    }
    if(ady_cas(*d,x,y,num)>=d->barco[tp].tam){
        d->jug[num].tablero[1][x][y]='H';
        do{
            n=hundido(d,num);
        }while(n!=0);
    }
}
}
