/*
 * Ejercicio 05 - Nivel Intermedio
 * int sumaPares(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa la suma de solo los numeros pares.
 */
#include <stdio.h>

/* Un numero es par cuando su residuo entre 2 es 0 (arr[i] % 2 == 0). */
int sumaPares(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 == 0) {
            suma = suma + arr[i];
        }
    }
    return suma;
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("La suma de los numeros pares es: %d\n", sumaPares(arr, tam));
    return 0;
}
