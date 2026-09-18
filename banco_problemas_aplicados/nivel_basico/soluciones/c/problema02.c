/*
 * Problema 02 - Voltaje Minimo en Banco Solar
 * double buscaMinimo(double Arr[], int tam)
 * Contexto: banco fotovoltaico. Devuelve el voltaje minimo para prevenir apagones.
 */
#include <stdio.h>

double buscaMinimo(double arr[], int tam) {
    double min = arr[0];              /* se compara contra el primer elemento */
    for (int i = 1; i < tam; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de celdas: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Voltaje de la celda %d (V): ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Voltaje minimo detectado: %.2f V\n", buscaMinimo(arr, tam));
    return 0;
}
