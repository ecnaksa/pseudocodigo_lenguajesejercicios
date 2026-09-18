/*
 * Problema 10 - Multiplicacion Cruzada Inversa en Retardos
 * Contexto: convolucion simple. C[i] = A[i] * B[tam-1-i] (vectores de 10),
 * guardando en C de izquierda a derecha.
 */
#include <stdio.h>

void multCruzada(int tam, double A[], double B[], double C[]) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] * B[tam - 1 - i];   /* primer A x ultimo B, etc. */
    }
    printf("Vector resultante C (cruce A * B):\n");
    for (int i = 0; i < tam; i++) {
        printf("C[%d] = %.2f\n", i, C[i]);
    }
}

int main(void) {
    int tam = 10;
    double A[tam], B[tam], C[tam];
    for (int i = 0; i < tam; i++) {
        printf("A[%d]: ", i);
        scanf("%lf", &A[i]);
        printf("B[%d]: ", i);
        scanf("%lf", &B[i]);
    }
    multCruzada(tam, A, B, C);
    return 0;
}
