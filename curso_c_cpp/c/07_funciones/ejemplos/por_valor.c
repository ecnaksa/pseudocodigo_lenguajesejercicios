/*
 * Paso por valor: la funcion recibe una COPIA, no modifica el original.
 */
#include <stdio.h>

void intentarCambiar(int x) {
    x = 100;               // solo cambia la copia local
    printf("  dentro de la funcion, x = %d\n", x);
}

int main(void) {
    int n = 5;
    printf("antes:   n = %d\n", n);
    intentarCambiar(n);
    printf("despues: n = %d  (no cambio)\n", n);
    return 0;
}
