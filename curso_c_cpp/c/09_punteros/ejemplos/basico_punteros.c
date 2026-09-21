/*
 * Lo basico: & (direccion de) y * (valor en la direccion).
 */
#include <stdio.h>

int main(void) {
    int edad = 25;
    int *p = &edad;        // p guarda la direccion de edad

    printf("valor de edad:      %d\n", edad);
    printf("direccion de edad:  %p\n", (void*) &edad);
    printf("valor de p (dir):   %p\n", (void*) p);
    printf("*p (valor apuntado):%d\n", *p);

    *p = 30;               // modificar edad a traves del puntero
    printf("edad ahora:         %d\n", edad);
    return 0;
}
