#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "estructura.h"
#include "datos_juego.h"
#include "turno.h"
#include "configurables.h"
#include "flota.h"
#include "Resumen.h"

int main(){
int a,b,r;
datos d;
d.inicializado=0;
setlocale(LC_ALL, "");
srand(time(NULL));
printf("HUNDIR LA FLOTA\n(presione <ENTER> para comenzar)");
getchar();
do{
r=0;
printf("\n-----------------------------------------\n");
do{
printf("\nMENU PRINCIPAL:\n1. Configuracion\n2. Jugar\n3. Salir\n(presiona el numero asociado)\n\nRespuesta: ");
scanf("%i",&a);
if((a<1)||(a>3))
    printf("\nERROR: Introduzca un numero valido\n\n");
}while((a<1)||(a>3));
if(a!=3){
    switch(a){
    case 1:
        do{
        printf("\n-----------------------------------------\n");
        do{
        printf("\nCONFIGURACION:\n1. Introducir datos\n2. Mostrar\n3. Borrar\n4. Guardar\n5. Cargar\n6. Volver\n(presiona el numero asociado)\n\nRespuesta: ");
        scanf("%i",&b);
        if((b<1)||(b>6))
        printf("\nERROR: Introduzca un numero valido\n\n");
        }while((b<1)||(b>6));
        if((d.inicializado==0)&&(b!=1)&&(b!=6)&&(b!=5))
            printf("\nERROR: Introduzca primero la configuracion necesaria en el apartado Configuracion -> Introducir datos o carga una partida en el apartado Configuracion -> Cargar\n");
        else{
            switch(b){
            case 1:
                introducir_datos(&d);
                break;
            case 2:
                mostrar_fichero(d);
                break;
            case 3:
                borrar_datos(&d);
                break;
            case 4:
                guardar(d);
                break;
            case 5:
                cargar(&d);
                break;
            case 6:
                r=1;
                break;
            }
        }
        }while(r==0);
        break;
    case 2:
        if(d.inicializado==0){
            printf("\nERROR: Introduzca primero la configuracion necesaria en el apartado Configuracion -> Introducir datos o carga una partida en el apartado Configuracion -> Cargar\n");
            r=1;
        }else{
            do{
            printf("\n-----------------------------------------\n");
            do{
            printf("\nJUGAR:\n1. Jugar partida\n2. Reiniciar partida\n3. Resumen\n4. Volver\n(presiona el numero asociado)\n\nRespuesta: ");
            scanf("%i",&b);
            if((b<1)||(b>4))
            printf("\nERROR: Introduzca un numero valido\n\n");
            }while((b<1)||(b>4));
            switch(b){
            case 1:
                if(d.flota==0){
                    flota(&d);
                    d.flota=1;
                }
                turno(&d);
                break;
            case 2:
                reiniciar(&d);
                break;
            case 3:
                Mostrar_resumen(d);
                break;
            case 4:
                r=1;
                break;
            }
        }while(r==0);
    }
    break;
    }
}
}while(r==1);
printf("\n-----------------------------------------\n");
printf("\nGracias por jugar\n");
return 0;
}
