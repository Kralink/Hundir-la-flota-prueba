#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

void rand_cord(int *a, char *c, int max){
*a=(rand() % (max)) + 1;
*c=(rand() % ((char)(max+64) - 'A' + 1)) + 'A';
}
