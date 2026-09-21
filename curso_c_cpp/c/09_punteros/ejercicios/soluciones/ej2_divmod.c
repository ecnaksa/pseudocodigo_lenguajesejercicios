/* Ejercicio 2 - Cociente y residuo por punteros. */
#include <stdio.h>

void divmod(int a, int b, int *coc, int *res) {
    *coc = a / b;
    *res = a % b;
}

int main(void) {
    int c, r;
    divmod(17, 5, &c, &r);
    printf("17 / 5 = %d, residuo %d\n", c, r);   // 3, residuo 2
    return 0;
}
