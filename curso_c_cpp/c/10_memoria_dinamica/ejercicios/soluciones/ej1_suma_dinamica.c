/* Ejercicio 1 - Suma de un arreglo dinamico. */
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

    int suma = 0;
    for (int i = 0; i < n; i++) suma += arr[i];
    printf("Suma: %d\n", suma);

    free(arr);
    return 0;
}
