#include <stdio.h>
#include "estructura.h"
#include "Resumen.h"


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

void Mostrar_resumen(datos partida){


int agua[2]={0,0},vacio[2]={0,0},tocado[2]={0,0},hundido[2]={0,0};//0:jug1 y 1:jug2
int i,j,p;

for(p=0;p<=1;p++){//p:variable jug[p],  z:tablero[z][][], i: filas , j:columnas
for(j=0;j<(partida.tam);j++){
    for(i=0;i<(partida.tam);i++){
        switch(partida.jug[p].tablero[1][i][j]){
        case '*':agua[p]=agua[p]+1; break;
        case '-':vacio[p]=vacio[p]+1; break;
        case 'T':tocado[p]=tocado[p]+1; break;
        case 'H':hundido[p]=hundido[p]; break;

        }
    }
}
}
    printf("\n-----------------------------------------\n");
    printf("\n|               |              Valor de las casillas            |            Barcos           |\n");
    printf("| Jugador       | Disparos | Vacias | Agua | Tocadas | Hundidas | Hundidos | Restan | Ganador |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| Jugador1      |    %i    |   %i   |  %i  |   %i    |    %i    |    %i    |   %i   |    %i    |\n",
            partida.jug[0].n_disp, vacio[0], agua[0], tocado[0], hundido[0], partida.jug[0].b_hund, (partida.n_barc - partida.jug[0].b_hund), partida.jug[0].ganad);
    printf("| Jugador2      |    %i    |   %i   |  %i  |   %i    |    %i    |    %i    |   %i   |    %i    |\n",
            partida.jug[1].n_disp, vacio[1], agua[1], tocado[1], hundido[1], partida.jug[1].b_hund, (partida.n_barc - partida.jug[1].b_hund), partida.jug[1].ganad);
    printf("-----------------------------------------------------------------------------------------------\n");

for(i=0;i<2;i++){
    printf("\nJugador %i:\nFLOTA",i+1);
    for(j=0;j<partida.tam+1;j++)
        printf("    ");
    printf("OPONENTE\n");
    mostrar_matriz(partida,i,partida.tam);
    printf("\n");
}
printf("Presione <ENTER> para continuar");
fflush(stdin);
getchar();
}
