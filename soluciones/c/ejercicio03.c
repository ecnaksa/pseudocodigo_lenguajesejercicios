/*
 * Ejercicio 03 - Nivel Basico
 * int cuentaImpares(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa la cantidad total de numeros impares que contiene.
 */
#include <stdio.h>

/*
 * Un numero es impar cuando el residuo de dividirlo entre 2 es distinto de 0.
 * En C el operador de residuo es '%' y la comparacion "distinto" es '!='.
 */
int cuentaImpares(int arr[], int tam) {
    int nimpar = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 != 0) {
            nimpar = nimpar + 1;
        }
    }
    return nimpar;
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

    printf("La cantidad de numeros impares es: %d\n", cuentaImpares(arr, tam));
    return 0;
}
