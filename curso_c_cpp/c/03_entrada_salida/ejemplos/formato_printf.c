/*
 * Control de formato en printf: decimales, ancho, alineacion.
 */
#include <stdio.h>

int main(void) {
    double pi = 3.14159265;

    printf("Por defecto: %f\n", pi);      // 3.141593
    printf("2 decimales: %.2f\n", pi);    // 3.14
    printf("0 decimales: %.0f\n", pi);    // 3

    printf("[%5d]\n", 42);                // [   42]  ancho 5, a la derecha
    printf("[%-5d]\n", 42);               // [42   ]  a la izquierda
    printf("Progreso: 50%%\n");           // %% imprime un % literal
    return 0;
}
