/*
 * Ejercicio 15 - Nivel Avanzado
 * int eliminaDuplicados(int Arr[], int tam)
 * Remueve todos los elementos duplicados de un arreglo y devuelve
 * el nuevo tamano logico del mismo.
 */
#include <stdio.h>

/*
 * Para cada elemento i se busca hacia adelante (j = i+1 ...) alguna copia.
 * Cuando se encuentra, se desplazan a la izquierda los elementos posteriores
 * para "tapar el hueco", se reduce el tamano logico (tam--) y se decrementa j
 * para volver a revisar la posicion que acaba de ocupar un valor nuevo.
 * Se devuelve el tamano logico resultante.
 */
int eliminaDuplicados(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < tam - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                tam = tam - 1;
                j = j - 1;
            }
        }
    }
    return tam;
}

int main(void) {
    int tam = 8;
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    int ntam = eliminaDuplicados(arr, tam);

    printf("Arreglo sin duplicados (%d elementos): ", ntam);
    for (int i = 0; i < ntam; i++) {
        printf("%d ", arr[i]);   /* "Escribir sin saltar" */
    }
    printf("\n");
    return 0;
}
