/*
 * Problema 37 - Calculo del Producto Punto de Vectores
 * double productoPunto(double A[], double B[], int n)
 * Contexto: operacion fundamental para filtros FIR. Acumulador de productos A[i]*B[i];
 * devuelve un ESCALAR (un solo numero). (Ver teoria/03_transformaciones_de_vector.md)
 */
#include <stdio.h>

double productoPunto(double A[], double B[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + A[i] * B[i];
    }
    return suma;
}

int main(void) {
    int n;
    printf("Ingrese el tamano de los vectores: ");
    scanf("%d", &n);

    double A[n], B[n];
    for (int i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%lf", &A[i]);
        printf("B[%d]: ", i);
        scanf("%lf", &B[i]);
    }

    printf("Producto punto A . B = %.2f\n", productoPunto(A, B, n));
    return 0;
}
