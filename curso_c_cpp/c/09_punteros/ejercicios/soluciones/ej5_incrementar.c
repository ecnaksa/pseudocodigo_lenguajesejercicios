/* Ejercicio 5 (reto) - Incrementar todos los elementos de un arreglo. */
#include <stdio.h>

void incrementar(int arr[], int n, int cantidad) {
    for (int i = 0; i < n; i++) {
        arr[i] += cantidad;        // modifica el arreglo original
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    incrementar(a, 5, 10);

    printf("Resultado: ");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);   // 11 12 13 14 15
    printf("\n");
    return 0;
}
