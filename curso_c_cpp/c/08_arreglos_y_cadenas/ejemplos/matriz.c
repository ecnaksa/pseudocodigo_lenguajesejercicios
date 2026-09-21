/*
 * Matriz (arreglo 2D) recorrida con dos bucles anidados.
 */
#include <stdio.h>

int main(void) {
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {          // filas
        for (int j = 0; j < 3; j++) {      // columnas
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
