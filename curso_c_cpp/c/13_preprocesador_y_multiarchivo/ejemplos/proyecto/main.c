/* main.c - usa el modulo mathutils. */
#include <stdio.h>
#include "mathutils.h"      /* comillas: busca en la carpeta del proyecto */

#define TITULO "== Demostracion de modulo =="

int main(void) {
    printf("%s\n", TITULO);
    printf("sumar(3, 4)   = %d\n", sumar(3, 4));
    printf("factorial(5)  = %d\n", factorial(5));
    return 0;
}
