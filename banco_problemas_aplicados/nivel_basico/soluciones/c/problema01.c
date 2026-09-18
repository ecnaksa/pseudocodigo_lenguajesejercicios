/*
 * Problema 01 - Suma de Muestras de Corriente ADC
 * double sumaCorrientes(double Arr[], int tam)
 * Contexto: monitoreo de corriente trifasica. Devuelve la sumatoria total (amperios).
 */
#include <stdio.h>

double sumaCorrientes(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    return suma;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Muestra %d (A): ", i);
        scanf("%lf", &arr[i]);   /* %lf = leer un double */
    }

    printf("Suma total de corrientes: %.2f A\n", sumaCorrientes(arr, tam));
    return 0;
}
