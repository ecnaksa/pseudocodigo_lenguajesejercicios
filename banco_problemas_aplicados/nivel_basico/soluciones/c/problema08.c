/*
 * Problema 08 - Umbral de Disipacion Termica Media
 * Contexto: 5 sensores de CPU. Calcular la media, contar cuantas temperaturas la superan
 * y desplegar esa lista.
 */
#include <stdio.h>

void umbralMedia(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    double media = suma / tam;       /* arr es double, la division ya es real */
    printf("Temperatura media (umbral): %.2f\n", media);

    int cuenta = 0;
    printf("Sensores por encima del umbral:\n");
    for (int i = 0; i < tam; i++) {
        if (arr[i] > media) {
            cuenta = cuenta + 1;
            printf("  sensor %d = %.2f\n", i, arr[i]);
        }
    }
    printf("Cantidad que supera el umbral: %d\n", cuenta);
}

int main(void) {
    int tam = 5;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Temperatura del sensor %d (C): ", i);
        scanf("%lf", &arr[i]);
    }
    umbralMedia(arr, tam);
    return 0;
}
