/* Ejercicio 1 - Duplicar el valor apuntado. */
#include <stdio.h>

void duplicar(int *n) {
    *n = *n * 2;
}

int main(void) {
    int x = 7;
    duplicar(&x);
    printf("x = %d\n", x);   // 14
    return 0;
}
