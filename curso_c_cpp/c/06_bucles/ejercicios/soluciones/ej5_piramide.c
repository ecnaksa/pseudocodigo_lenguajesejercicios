/* Ejercicio 5 (reto) - Piramide de asteriscos con bucles anidados. */
#include <stdio.h>

int main(void) {
    int h;
    printf("Altura: ");
    scanf("%d", &h);

    for (int fila = 1; fila <= h; fila++) {
        for (int col = 1; col <= fila; col++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
