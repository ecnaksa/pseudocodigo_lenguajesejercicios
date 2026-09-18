/*
 * Problema 09 - Superposicion Lineal de Dos Canales (A + B)
 * Contexto: suma de senales de dos microfonos. C[i] = A[i] + B[i] (vectores de 5).
 */
#include <stdio.h>

void superpone(double A[], double B[], double C[], int tam) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] + B[i];
    }
    printf("Vector resultante C (A + B):\n");
    for (int i = 0; i < tam; i++) {
        printf("C[%d] = %.2f\n", i, C[i]);
    }
}

int main(void) {
    int tam = 5;
    double A[tam], B[tam], C[tam];
    for (int i = 0; i < tam; i++) {
        printf("Canal A, muestra %d: ", i);
        scanf("%lf", &A[i]);
        printf("Canal B, muestra %d: ", i);
        scanf("%lf", &B[i]);
    }
    superpone(A, B, C, tam);
    return 0;
}
