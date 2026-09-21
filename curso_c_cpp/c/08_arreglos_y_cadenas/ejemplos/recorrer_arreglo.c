/*
 * Declarar, llenar y recorrer un arreglo. Suma, maximo y promedio.
 */
#include <stdio.h>

int main(void) {
    int notas[5] = {90, 85, 70, 95, 60};
    int n = 5;

    int suma = 0, maximo = notas[0];
    for (int i = 0; i < n; i++) {
        suma += notas[i];
        if (notas[i] > maximo) maximo = notas[i];
    }

    printf("Suma: %d\n", suma);
    printf("Maximo: %d\n", maximo);
    printf("Promedio: %.2f\n", (double) suma / n);
    return 0;
}
