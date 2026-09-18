/*
 * Problema 25 - Particion Pares/Impares en Vector
 * Contexto: procesamiento multiplexado. Reorganizar el arreglo colocando primero los valores
 * que estan en INDICES pares (0,2,4,...) y luego los de indices impares (1,3,5,...),
 * usando un vector auxiliar de salida.
 */
#include <stdio.h>

void particiona(int arr[], int tam, int res[]) {
    int k = 0;
    for (int i = 0; i < tam; i++) {          /* primero los indices pares */
        if (i % 2 == 0) {
            res[k] = arr[i];
            k = k + 1;
        }
    }
    for (int i = 0; i < tam; i++) {          /* luego los indices impares */
        if (i % 2 != 0) {
            res[k] = arr[i];
            k = k + 1;
        }
    }
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &tam);

    int arr[tam], res[tam];
    for (int i = 0; i < tam; i++) {
        printf("Dato %d: ", i);
        scanf("%d", &arr[i]);
    }

    particiona(arr, tam, res);

    printf("Vector particionado (pares | impares): ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
