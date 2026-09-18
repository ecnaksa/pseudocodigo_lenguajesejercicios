/*
 * Problema 31 - Busqueda de Fila con Mayor Consumo
 * Contexto: subestacion representada por una matriz de consumos. Devuelve el indice de la
 * fila cuya suma (consumo acumulado) es la mayor.
 */
#include <stdio.h>

int filaMayorConsumo(int n, int m, double mat[n][m]) {
    int filaMax = 0;
    double mayorSuma = 0.0;

    /* suma de la fila 0 como referencia inicial */
    for (int j = 0; j < m; j++) {
        mayorSuma = mayorSuma + mat[0][j];
    }

    for (int i = 1; i < n; i++) {
        double suma = 0.0;
        for (int j = 0; j < m; j++) {
            suma = suma + mat[i][j];
        }
        if (suma > mayorSuma) {
            mayorSuma = suma;
            filaMax = i;
        }
    }
    return filaMax;
}

int main(void) {
    int n, m;
    printf("Numero de buses/filas (N): ");
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

    printf("La fila con mayor consumo es la %d.\n", filaMayorConsumo(n, m, mat));
    return 0;
}
