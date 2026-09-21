/*
 * realloc: empezar pequeno y crecer el arreglo segun se necesita.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidad = 2;
    int *arr = malloc(capacidad * sizeof(int));
    if (arr == NULL) return 1;

    int cantidad = 0;
    for (int valor = 10; valor <= 50; valor += 10) {
        if (cantidad == capacidad) {           // lleno: duplicar capacidad
            capacidad *= 2;
            int *tmp = realloc(arr, capacidad * sizeof(int));
            if (tmp == NULL) { free(arr); return 1; }
            arr = tmp;
        }
        arr[cantidad++] = valor;
    }

    printf("Guardados %d (capacidad %d): ", cantidad, capacidad);
    for (int i = 0; i < cantidad; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
