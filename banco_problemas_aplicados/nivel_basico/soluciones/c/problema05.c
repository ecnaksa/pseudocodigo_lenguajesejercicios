/*
 * Problema 05 - Consumo Exclusivo de Cargas Pares
 * double sumaPares(double Arr[], int tam)
 * Contexto: circuitos en fases pares de un multiplexor. Acumula los valores en INDICES pares.
 *
 * OJO: condicion sobre el INDICE (i % 2 == 0), no sobre el valor.
 */
#include <stdio.h>

double sumaPares(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {            /* i par: 0, 2, 4, ... */
            suma = suma + arr[i];
        }
    }
    return suma;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de lecturas: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Lectura %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Suma de las cargas en indices pares: %.2f\n", sumaPares(arr, tam));
    return 0;
}
