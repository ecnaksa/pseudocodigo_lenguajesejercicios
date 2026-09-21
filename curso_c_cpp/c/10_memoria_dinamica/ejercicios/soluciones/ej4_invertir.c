/* Ejercicio 4 (reto) - Invertir un arreglo dinamico in situ. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    /* invertir intercambiando extremos hacia el centro */
    for (int i = 0; i < n / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }

    printf("Invertido: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
