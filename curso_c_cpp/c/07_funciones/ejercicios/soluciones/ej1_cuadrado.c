/* Ejercicio 1 - Funcion cuadrado. */
#include <stdio.h>

int cuadrado(int n) {
    return n * n;
}

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("%d al cuadrado = %d\n", i, cuadrado(i));
    }
    return 0;
}
