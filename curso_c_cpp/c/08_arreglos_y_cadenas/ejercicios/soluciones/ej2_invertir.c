/* Ejercicio 2 - Mostrar un arreglo al reves. */
#include <stdio.h>

int main(void) {
    int a[5];
    printf("Cinco enteros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    printf("Al reves: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
