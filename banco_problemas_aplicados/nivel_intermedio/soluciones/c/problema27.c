/*
 * Problema 27 - Calculo de Derivada Discreta de Senal
 * Contexto: tasa de cambio de una senal digital. Vector de diferencias sucesivas
 * dv[i] = v[i+1] - v[i]. El resultado tiene UN elemento menos (n-1).
 */
#include <stdio.h>

void derivada(double v[], int n, double dv[]) {
    for (int i = 0; i < n - 1; i++) {   /* hasta n-2 porque se usa v[i+1] */
        dv[i] = v[i + 1] - v[i];
    }
}

int main(void) {
    int n;
    printf("Ingrese el numero de voltajes: ");
    scanf("%d", &n);

    double v[n];
    for (int i = 0; i < n; i++) {
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
    }

    if (n < 2) {
        printf("Se necesitan al menos 2 muestras para la derivada.\n");
        return 0;
    }

    double dv[n - 1];
    derivada(v, n, dv);

    printf("Derivada discreta (delta v): ");
    for (int i = 0; i < n - 1; i++) {
        printf("%.2f ", dv[i]);
    }
    printf("\n");
    return 0;
}
