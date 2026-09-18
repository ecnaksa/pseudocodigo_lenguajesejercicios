/*
 * Problema 34 - Verificacion de Orden Estricto Creciente
 * bool esCreciente(double Arr[], int tam)
 * Contexto: validar que un vector de calibracion esta estrictamente ordenado ascendente
 * (sin saltos anomalos): cada Arr[i] < Arr[i+1].
 */
#include <stdio.h>
#include <stdbool.h>

bool esCreciente(double arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {   /* hasta tam-2 porque se usa Arr[i+1] */
        if (!(arr[i] < arr[i + 1])) {     /* estricto: si hay igual o menor, falla */
            return false;
        }
    }
    return true;
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Calibracion %d: ", i);
        scanf("%lf", &arr[i]);
    }

    if (esCreciente(arr, tam)) {
        printf("El vector esta estrictamente ordenado de forma ascendente.\n");
    } else {
        printf("El vector NO esta estrictamente ordenado.\n");
    }
    return 0;
}
