#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "estructura.h"

void rand_cord(char *c, int *a, int nj, datos d){
int n=-1,i,j;
char let[d.tam*d.tam];
int num[d.tam*d.tam];
for(i=0;i<d.tam;i++){
    for(j=0;j<d.tam;j++){
        if(d.jug[nj].tablero[1][i][j]=='-'){
            n++;
            let[n]=(char)i+65;
            num[n]=j+1;
        }
    }
}
j=(rand() % (n+1));
*c=let[j];
*a=num[j];
}
void ady_cord(char *l, int *nu, char c, int a, int nj, datos d){
int n=-1,j;
char i;
char let[8];
int num[8];
for(i=c-1;i<=c+1;i++){
    for(j=a-1;j<=a+1;j++){
        if((i>='A')&&(i<=(char)d.tam+64)&&(j>=1)&&(j<=d.tam)){
            if(d.jug[nj].tablero[1][(int)i-65][j-1]=='-'){
                n++;
                let[n]=i;
                num[n]=j;
            }
        }
    }
}
j=(rand() % (n+1));
*l=let[j];
*nu=num[j];
}

int dir_cord(char let1, int num1,char let2, int num2, char *c, int *a, int nj, datos d){
int n,j,dir,n1,ret=0;
char i;
char let[2];
int num[2];
if((((int)(let1-let2)>0)&&(num1-num2>0))||(((int)(let1-let2)<0)&&(num1-num2<0)))
    dir=1; //Diagonal '\'
else if((int)(let1-let2)==0)
    dir=2; //Horizontal
else if((((int)(let1-let2)<0)&&(num1-num2>0))||(((int)(let1-let2)>0)&&(num1-num2<0)))
    dir=3; //Diagonal '/'
else
    dir=4; //Vertical
switch(dir){
case 1:
    n=-1;
    n1=-1;
    for(i=0;i<=2;i=i+2){
        if(((int)let1-66+i>=0)&&(num1-2+i>=0)&&((int)let1-66+i<d.tam)&&(num1-2+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let1-66+i][num1-2+i]=='-'){
                n++;
                n1=n;
                let[n]=let1-1+i;
                num[n]=num1-1+i;
            }
        }
        if(((int)let2-66+i>=0)&&(num2-2+i>=0)&&((int)let2-66+i<d.tam)&&(num2-2+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let2-66+i][num2-2+i]=='-'){
                n++;
                let[n]=let2-1+i;
                num[n]=num2-1+i;
            }
        }
    }
    break;
case 2:
    n=-1;
    n1=-1;
    for(i=0;i<=2;i=i+2){
        if((num1-2+i>=0)&&(num1-2+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let1-65][num1-2+i]=='-'){
                n++;
                n1=n;
                let[n]=let1;
                num[n]=num1-1+i;
            }
        }
        if((num2-2+i>=0)&&(num2-2+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let2-65][num2-2+i]=='-'){
                n++;
                let[n]=let2;
                num[n]=num2-1+i;
            }
        }
    }
    break;
case 3:
    n=-1;
    n1=-1;
    for(i=0;i<=2;i=i+2){
        if(((int)let1-66+i>=0)&&(num1-i>=0)&&((int)let1-66+i<d.tam)&&(num1-i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let1-66+i][num1-i]=='-'){
                n++;
                n1=n;
                let[n]=let1-1+i;
                num[n]=num1+1-i;
            }
        }
        if(((int)let2-66+i>=0)&&(num2-i>=0)&&((int)let2-66+i<d.tam)&&(num2-i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let2-66+i][num2-i]=='-'){
                n++;
                let[n]=let2-1+i;
                num[n]=num2+1-i;
            }
        }
    }
    break;
case 4:
    n=-1;
    n1=-1;
    for(i=0;i<=2;i=i+2){
        if(((int)let1-66+i>=0)&&((int)let1-66+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let1-66+i][num1-1]=='-'){
                n++;
                n1=n;
                let[n]=let1-1+i;
                num[n]=num1;
            }
        }
        if(((int)let2-66+i>=0)&&((int)let2-66+i<d.tam)){
            if(d.jug[nj].tablero[1][(int)let2-66+i][num2-1]=='-'){
                n++;
                let[n]=let2-1+i;
                num[n]=num2;
            }
        }
    }
    break;
}
j=(rand() % (n+1));
*c=let[j];
*a=num[j];
if((n1>=0)&&(j==n1))
    ret=1;
return ret;
}
