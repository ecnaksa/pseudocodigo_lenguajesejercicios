/*
 * Problema 38 - Inversion Condicional de Negativos
 * Contexto: rectificacion digital por software de una senal bipolar. Aplicar valor absoluto
 * solo donde Arr[i] < 0 (los positivos quedan igual).
 */
#include <stdio.h>

void rectifica(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];        /* convertir el negativo en positivo */
        }
    }
}

int main(void) {
    int n;
    printf("Ingrese el numero de mediciones: ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Medicion %d: ", i);
        scanf("%lf", &arr[i]);
    }

    rectifica(arr, n);

    printf("Senal rectificada: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
