/*
 * Problema 13 - Calculo de Potencia Aparente Promedio
 * double potenciaPromedio(double V[], double I[], int n)
 * Contexto: arreglos de voltajes y corrientes instantaneas. Suma de productos V[i]*I[i]
 * y luego el promedio (dividir entre n).
 */
#include <stdio.h>

double potenciaPromedio(double V[], double I[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + V[i] * I[i];   /* producto punto de V e I */
    }
    return suma / n;                 /* promedio */
}

int main(void) {
    int n;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &n);

    double V[n], I[n];
    for (int i = 0; i < n; i++) {
        printf("V[%d] (V): ", i);
        scanf("%lf", &V[i]);
        printf("I[%d] (A): ", i);
        scanf("%lf", &I[i]);
    }

    printf("Potencia aparente promedio: %.2f\n", potenciaPromedio(V, I, n));
    return 0;
}
