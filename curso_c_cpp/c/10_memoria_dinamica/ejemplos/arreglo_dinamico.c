/*
 * Arreglo cuyo tamano lo decide el usuario, con malloc/free.
 * Prueba: printf "4\n" | ./prog
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Cuantos numeros? ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));    // memoria para n enteros
    if (arr == NULL) {
        printf("Sin memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * (i + 1);        // cuadrados
    }

    printf("Cuadrados: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);                             // liberar
    arr = NULL;
    return 0;
}
