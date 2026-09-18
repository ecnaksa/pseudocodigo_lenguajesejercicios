/*
 * for: contar del 1 al 10 y del 10 al 1.
 */
#include <stdio.h>

int main(void) {
    printf("Ascendente: ");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Descendente: ");
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
