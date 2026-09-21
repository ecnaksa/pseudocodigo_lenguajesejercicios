/* Ejercicio 2 - Copiar un arreglo a memoria nueva. */
#include <stdio.h>
#include <stdlib.h>

int *copiar(int *origen, int n) {
    int *nuevo = malloc(n * sizeof(int));
    if (nuevo == NULL) return NULL;
    for (int i = 0; i < n; i++) nuevo[i] = origen[i];
    return nuevo;
}

int main(void) {
    int a[4] = {5, 10, 15, 20};
    int *b = copiar(a, 4);
    if (b == NULL) return 1;

    printf("Copia: ");
    for (int i = 0; i < 4; i++) printf("%d ", b[i]);
    printf("\n");

    free(b);
    return 0;
}
