/*
 * Problema 36 - Concatenacion Segura de Dos Buffers
 * Contexto: unir dos vectores de tramas en un tercer vector de mayor capacidad, copiando
 * secuencialmente y sin desbordar la memoria (C tiene tamano n1 + n2).
 */
#include <stdio.h>

void concatena(int A[], int nA, int B[], int nB, int C[]) {
    int k = 0;
    for (int i = 0; i < nA; i++) {   /* primero todo A */
        C[k] = A[i];
        k = k + 1;
    }
    for (int i = 0; i < nB; i++) {   /* luego todo B */
        C[k] = B[i];
        k = k + 1;
    }
}

int main(void) {
    int nA, nB;
    printf("Tamano del Vector 1: ");
    scanf("%d", &nA);
    int A[nA];
    for (int i = 0; i < nA; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Tamano del Vector 2: ");
    scanf("%d", &nB);
    int B[nB];
    for (int i = 0; i < nB; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    int C[nA + nB];
    concatena(A, nA, B, nB, C);

    printf("Vector combinado (%d elementos): ", nA + nB);
    for (int i = 0; i < nA + nB; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
    return 0;
}
