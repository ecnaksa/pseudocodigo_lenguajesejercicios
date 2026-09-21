/* Ejercicio 4 - Recorrer con aritmetica de punteros. */
#include <stdio.h>

int main(void) {
    int a[5] = {2, 4, 6, 8, 10};
    int *p = a;

    int suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += *(p + i);          // equivale a a[i]
    }
    printf("Suma: %d\n", suma);    // 30
    return 0;
}
