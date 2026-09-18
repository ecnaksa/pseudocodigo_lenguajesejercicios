/*
 * Problema 18 - Comparacion de Dos Canales de Telemetria
 * bool sonIguales(int A[], int B[], int tam)
 * Contexto: dos vectores de igual tamano. Devuelve true si son identicos elemento por elemento.
 */
#include <stdio.h>
#include <stdbool.h>

bool sonIguales(int A[], int B[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (A[i] != B[i]) {
            return false;            /* en cuanto hay una diferencia, no son iguales */
        }
    }
    return true;
}

int main(void) {
    int tam;
    printf("Ingrese el tamano de los canales: ");
    scanf("%d", &tam);

    int A[tam], B[tam];
    for (int i = 0; i < tam; i++) {
        printf("Canal A, dato %d: ", i);
        scanf("%d", &A[i]);
        printf("Canal B, dato %d: ", i);
        scanf("%d", &B[i]);
    }

    if (sonIguales(A, B, tam)) {
        printf("Los dos canales son identicos.\n");
    } else {
        printf("Los canales difieren.\n");
    }
    return 0;
}
