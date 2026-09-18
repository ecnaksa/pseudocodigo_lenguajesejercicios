/*
 * Problema 29 - Suma de Matriz de Nodos por Filas
 * Contexto: red de distribucion mallada. Recibe una matriz N x M y devuelve un arreglo
 * unidimensional con la suma de cada fila (bucle anidado).
 *
 * En C una matriz se pasa indicando sus dimensiones: mat[n][m] (arreglo 2D de longitud
 * variable, C99). (Ver teoria/02_matrices_2d.md)
 */
#include <stdio.h>

void sumaFilas(int n, int m, double mat[n][m], double res[]) {
    for (int i = 0; i < n; i++) {
        double suma = 0.0;
        for (int j = 0; j < m; j++) {
            suma = suma + mat[i][j];
        }
        res[i] = suma;
    }
}

int main(void) {
    int n, m;
    printf("Numero de filas (N): ");
    scanf("%d", &n);
    printf("Numero de columnas (M): ");
    scanf("%d", &m);

    double mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }

    double res[n];
    sumaFilas(n, m, mat, res);

    printf("Suma por filas:\n");
    for (int i = 0; i < n; i++) {
        printf("  fila %d = %.2f\n", i, res[i]);
    }
    return 0;
}
