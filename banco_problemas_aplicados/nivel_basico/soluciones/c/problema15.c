/*
 * Problema 15 - Conteo de Muestras Saturadas (Overflow)
 * int cuentaSaturadas(int Arr[], int tam)
 * Contexto: conversiones de un ADC de 10 bits (0..1023). Contar cuantas llegaron al
 * limite superior exacto de 1023 cuentas.
 */
#include <stdio.h>

int cuentaSaturadas(int arr[], int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 1023) {        /* 1023 = valor maximo de un ADC de 10 bits */
            contador = contador + 1;
        }
    }
    return contador;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de conversiones: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Conversion %d (0..1023): ", i);
        scanf("%d", &arr[i]);
    }

    printf("Muestras saturadas (== 1023): %d\n", cuentaSaturadas(arr, tam));
    return 0;
}
