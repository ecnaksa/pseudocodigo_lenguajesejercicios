/*
 * Problema 19 - Inversion Espejo de Primera Mitad
 * void espejoPrimeraMitad(double Arr[], int n)
 * Contexto: pruebas de impulso. Copiar la primera mitad del vector reflejada en la segunda
 * mitad, dejando el arreglo simetrico:  Arr[n-1-i] = Arr[i].
 */
#include <stdio.h>

void espejoPrimeraMitad(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        arr[n - 1 - i] = arr[i];     /* la posicion espejo copia el valor de la primera mitad */
    }
}

int main(void) {
    int n;
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Dato %d: ", i);
        scanf("%lf", &arr[i]);
    }

    espejoPrimeraMitad(arr, n);

    printf("Vector simetrizado: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
