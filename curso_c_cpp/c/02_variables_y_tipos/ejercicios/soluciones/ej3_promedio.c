/* Ejercicio 3 - Promedio de tres enteros con decimales. */
#include <stdio.h>

int main(void) {
    int a = 7, b = 8, c = 10;
    int suma = a + b + c;

    /* suma/3 seria division entera; forzamos real con (double) */
    double promedio = (double) suma / 3;

    printf("Suma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);
    return 0;
}
