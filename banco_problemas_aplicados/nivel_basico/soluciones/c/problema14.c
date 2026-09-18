/*
 * Problema 14 - Ordenamiento Lineal Simple por Intercambio
 * Contexto: 8 valores de calibracion, orden ascendente con el metodo de intercambio
 * (burbuja): dos bucles anidados comparando pares adyacentes.
 */
#include <stdio.h>

void ordenaIntercambio(double arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int f = 0; f < tam - 1 - i; f++) {
            if (arr[f] > arr[f + 1]) {
                double aux = arr[f];
                arr[f] = arr[f + 1];
                arr[f + 1] = aux;
            }
        }
    }
}

int main(void) {
    int tam = 8;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Valor de calibracion %d: ", i);
        scanf("%lf", &arr[i]);
    }

    ordenaIntercambio(arr, tam);

    printf("Valores ordenados: ");
    for (int i = 0; i < tam; i++) {
        printf("%.2f ", arr[i]);     /* escribir sin saltar */
    }
    printf("\n");
    return 0;
}
