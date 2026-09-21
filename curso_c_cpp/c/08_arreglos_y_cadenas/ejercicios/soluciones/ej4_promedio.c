/* Ejercicio 4 - Promedio de un arreglo con una funcion. */
#include <stdio.h>

double promedio(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) suma += arr[i];
    return (double) suma / n;
}

int main(void) {
    int datos[] = {10, 20, 30, 40};
    int n = 4;
    printf("Promedio: %.2f\n", promedio(datos, n));
    return 0;
}
