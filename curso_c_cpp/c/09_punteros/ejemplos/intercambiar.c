/*
 * Intercambiar dos variables con punteros (imposible por valor).
 */
#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 1, y = 2;
    printf("Antes:   x=%d, y=%d\n", x, y);
    intercambiar(&x, &y);          // pasamos las DIRECCIONES
    printf("Despues: x=%d, y=%d\n", x, y);
    return 0;
}
