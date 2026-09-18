/*
 * Problema 06 - Frecuencia de Falla Especifica en PLC
 * int cuentaRepeticiones(int Arr[], int x, int tam)
 * Contexto: monitoreo industrial. Cuenta cuantas veces se repite el codigo de error x.
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
    printf("Ingrese el numero de registros: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Registro %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Ingrese el codigo de error a rastrear (x): ");
    scanf("%d", &x);

    printf("El codigo %d se repite %d veces.\n", x, cuentaRepeticiones(arr, x, tam));
    return 0;
}
