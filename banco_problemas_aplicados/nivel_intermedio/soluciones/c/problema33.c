/*
 * Problema 33 - Compresion de Datos por Submuestreo
 * Contexto: reducir la tasa de muestreo tomando solo las muestras en indices multiplos de K
 * (0, K, 2K, ...). Devuelve el nuevo tamano del vector comprimido.
 */
#include <stdio.h>

int submuestrea(double arr[], int n, int k, double res[]) {
    int j = 0;
    for (int i = 0; i < n; i = i + k) {   /* i salta de K en K */
        res[j] = arr[i];
        j = j + 1;
    }
    return j;                              /* cantidad de muestras conservadas */
}

int main(void) {
    int n, k;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Muestra %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Ingrese el factor de compresion K: ");
    scanf("%d", &k);

    double res[n];
    int nuevo = submuestrea(arr, n, k, res);

    printf("Vector comprimido (%d muestras): ", nuevo);
    for (int i = 0; i < nuevo; i++) {
        printf("%.2f ", res[i]);
    }
    printf("\n");
    return 0;
}
