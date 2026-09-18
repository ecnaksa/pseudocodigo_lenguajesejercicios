/*
 * Ejercicio 01 - Nivel Basico
 * int sumaElementos(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa el resultado de sumar todos sus elementos.
 */
#include <stdio.h>

/* La funcion recorre el arreglo acumulando cada elemento en 'suma'. */
int sumaElementos(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    return suma;
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    /* Arreglo de longitud variable: su tamano se conoce en tiempo de ejecucion (C99). */
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("La suma de los elementos del arreglo es: %d\n", sumaElementos(arr, tam));
    return 0;
}
