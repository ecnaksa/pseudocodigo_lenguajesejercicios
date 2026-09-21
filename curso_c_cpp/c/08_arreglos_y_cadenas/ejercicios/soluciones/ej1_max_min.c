/* Ejercicio 1 - Maximo y minimo de un arreglo. */
#include <stdio.h>

int main(void) {
    int a[6] = {23, 8, 45, 12, 4, 30};
    int n = 6;

    int maximo = a[0], minimo = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maximo) maximo = a[i];
        if (a[i] < minimo) minimo = a[i];
    }
    printf("Maximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);
    return 0;
}
