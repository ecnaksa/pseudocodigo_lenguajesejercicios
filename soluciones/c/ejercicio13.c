/*
 * Ejercicio 13 - Nivel Avanzado
 * bool esPalindromo(int Arr[], int tam)
 * Determina si un arreglo de enteros es simetrico
 * (se lee igual de izquierda a derecha que de derecha a izquierda).
 */
#include <stdio.h>
#include <stdbool.h>   /* Da acceso al tipo bool y a los valores true / false. */

/*
 * La funcion COMPARA (no modifica) los extremos hacia el centro.
 * En cuanto encuentra un par que no coincide, devuelve false.
 * Si termina el recorrido sin diferencias, el arreglo es simetrico: devuelve true.
 */
bool esPalindromo(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        if (arr[i] != arr[tam - 1 - i]) {
            return false;
        }
    }
    return true;
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

    if (esPalindromo(arr, tam)) {
        printf("El arreglo es simetrico (palindromo).\n");
    } else {
        printf("El arreglo NO es simetrico.\n");
    }
    return 0;
}
