/*
 * Ejercicio 09 - Nivel Intermedio
 * Llenar dos vectores A y B de 5 elementos cada uno, sumar elemento a elemento
 * (A[i] + B[i]) almacenando el resultado en un vector C, e imprimir C.
 */
#include <stdio.h>

/*
 * Los tres arreglos se pasan como parametros. Como en C un arreglo se pasa
 * por su direccion, las modificaciones que la funcion hace sobre C[] se ven
 * reflejadas en el arreglo original de main.
 */
void sumarVectores(int A[], int B[], int C[], int tam) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] + B[i];
    }
    printf("Vector C (resultado A + B):\n");
    for (int i = 0; i < tam; i++) {
        printf("C[%d] = %d\n", i, C[i]);
    }
}

int main(void) {
    int tam = 5;
    int A[tam], B[tam], C[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d de A: ", i);
        scanf("%d", &A[i]);
        printf("Ingrese el elemento %d de B: ", i);
        scanf("%d", &B[i]);
    }
    sumarVectores(A, B, C, tam);
    return 0;
}
