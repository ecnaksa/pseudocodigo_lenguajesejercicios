/*
 * Problema 35 - Remocion de Valores Anomalos (Outliers)
 * Contexto: identificar lecturas que excedan en mas de 2 desviaciones estandar el promedio
 * y reemplazarlas por el valor medio local (promedio de sus vecinos).
 * (Ver teoria/04_estadistica_y_outliers.md)
 */
#include <stdio.h>
#include <math.h>          /* sqrt, fabs */

void removeOutliers(double arr[], int n, double res[]) {
    /* 1) media */
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + arr[i];
    }
    double media = suma / n;

    /* 2) desviacion estandar (poblacional) */
    double sumaCuad = 0.0;
    for (int i = 0; i < n; i++) {
        sumaCuad = sumaCuad + (arr[i] - media) * (arr[i] - media);
    }
    double desv = sqrt(sumaCuad / n);

    /* 3) reemplazar los outliers por la media de sus vecinos (usando los valores ORIGINALES) */
    for (int i = 0; i < n; i++) {
        if (fabs(arr[i] - media) > 2.0 * desv) {
            if (i == 0) {
                res[i] = arr[i + 1];                    /* extremo izquierdo */
            } else if (i == n - 1) {
                res[i] = arr[i - 1];                    /* extremo derecho */
            } else {
                res[i] = (arr[i - 1] + arr[i + 1]) / 2.0;
            }
        } else {
            res[i] = arr[i];
        }
    }
}

int main(void) {
    int n;
    printf("Ingrese el numero de lecturas: ");
    scanf("%d", &n);

    double arr[n], res[n];
    for (int i = 0; i < n; i++) {
        printf("Lectura %d: ", i);
        scanf("%lf", &arr[i]);
    }

    removeOutliers(arr, n, res);

    printf("Vector depurado: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", res[i]);
    }
    printf("\n");
    return 0;
}
