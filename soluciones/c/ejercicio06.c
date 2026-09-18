/*
 * Ejercicio 06 - Nivel Intermedio
 * int cuentaRepeticiones(int Arr[], int x, int tam)
 * Regresa el numero de veces que se repite el valor x dentro del arreglo.
 */
#include <stdio.h>

int cuentaRepeticiones(int arr[], int x, int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == x) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main(void) {
    int tam, x;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Ingrese el valor a contar (x): ");
    scanf("%d", &x);

    printf("El valor %d se repite %d veces.\n", x, cuentaRepeticiones(arr, x, tam));
    return 0;
}
