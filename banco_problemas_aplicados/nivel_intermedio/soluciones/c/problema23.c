/*
 * Problema 23 - Inversion Espectral In-Place en Memoria
 * void invertirBuffer(int Arr[], int tam)
 * Contexto: optimizacion de RAM. Invierte el orden del arreglo SIN vectores auxiliares
 * (solo una variable temporal), intercambiando Arr[i] con Arr[tam-1-i].
 */
#include <stdio.h>

void invertirBuffer(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];                    /* unica variable temporal, no un arreglo */
        arr[i] = arr[tam - 1 - i];
        arr[tam - 1 - i] = aux;
    }
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del buffer: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Dato %d: ", i);
        scanf("%d", &arr[i]);
    }

    invertirBuffer(arr, tam);

    printf("Buffer invertido: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
