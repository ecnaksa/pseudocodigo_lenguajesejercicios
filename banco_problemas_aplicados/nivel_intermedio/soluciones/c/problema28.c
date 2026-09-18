/*
 * Problema 28 - Normalizacion Lineal de Rango [0.0, 1.0]
 * Contexto: escalamiento de senales para redes neuronales. Se divide cada valor entre el
 * maximo ABSOLUTO hallado: Arr[i] / maxVal. Si los datos son >= 0 el resultado queda en
 * [0,1]; si hay negativos, en [-1,1]. (Ver teoria/03_transformaciones_de_vector.md)
 */
#include <stdio.h>
#include <math.h>          /* fabs: valor absoluto de un double */

void normaliza(double arr[], int n) {
    double maxVal = fabs(arr[0]);
    for (int i = 1; i < n; i++) {
        if (fabs(arr[i]) > maxVal) {
            maxVal = fabs(arr[i]);
        }
    }
    if (maxVal == 0.0) {
        return;                        /* todos son 0: no se puede dividir, se deja igual */
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / maxVal;
    }
}

int main(void) {
    int n;
    printf("Ingrese el numero de valores: ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i);
        scanf("%lf", &arr[i]);
    }

    normaliza(arr, n);

    printf("Vector normalizado: ");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");
    return 0;
}
