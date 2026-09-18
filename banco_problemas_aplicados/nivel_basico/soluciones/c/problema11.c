/*
 * Problema 11 - Deteccion de Pico Maximo Absoluto
 * Contexto: 15 muestras de osciloscopio (valores unicos). Imprimir el valor maximo y
 * su posicion (indice) en el tiempo.
 */
#include <stdio.h>

void picoMaximo(double arr[], int tam) {
    double mayor = arr[0];
    int posicion = 0;
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            posicion = i;
        }
    }
    printf("Pico maximo: %.2f\n", mayor);
    printf("Posicion (indice) del pico: %d\n", posicion);
}

int main(void) {
    int tam = 15;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Muestra %d (V): ", i);
        scanf("%lf", &arr[i]);
    }
    picoMaximo(arr, tam);
    return 0;
}
