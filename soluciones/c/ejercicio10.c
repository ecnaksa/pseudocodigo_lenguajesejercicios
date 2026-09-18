/*
 * Ejercicio 10 - Nivel Intermedio
 * Leer dos vectores A y B de 10 elementos. Multiplicar el primer elemento de A
 * por el ultimo de B, el segundo de A por el penultimo de B, y asi sucesivamente.
 * Guardar el resultado en un vector C de izquierda a derecha:  C[i] = A[i] * B[tam-1-i].
 */
#include <stdio.h>

void multiplicarVectores(int tam, int A[], int B[], int C[]) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] * B[tam - 1 - i];
    }
    printf("Vector C (resultado del cruce A * B):\n");
    for (int i = 0; i < tam; i++) {
        printf("C[%d] = %d\n", i, C[i]);
    }
}

int main(void) {
    int tam = 10;
    int A[tam], B[tam], C[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d de A: ", i);
        scanf("%d", &A[i]);
        printf("Ingrese el elemento %d de B: ", i);
        scanf("%d", &B[i]);
    }
    multiplicarVectores(tam, A, B, C);
    return 0;
}
