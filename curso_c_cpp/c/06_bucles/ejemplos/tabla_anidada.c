/*
 * Bucles anidados: tabla de multiplicar del 1 al 5.
 */
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("%3d", i * j);    // %3d alinea en ancho 3
        }
        printf("\n");                // nueva fila
    }
    return 0;
}
