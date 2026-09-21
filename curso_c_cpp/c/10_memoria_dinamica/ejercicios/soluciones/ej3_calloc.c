/* Ejercicio 3 - calloc (memoria ya en cero) y rellenar con el indice. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 6;
    int *arr = calloc(n, sizeof(int));    // todos inician en 0
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        arr[i] += i;                       // 0 + i
    }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);   // 0 1 2 3 4 5
    printf("\n");

    free(arr);
    return 0;
}
