/*
 * Problema 32 - Conteo de Nodos con Voltaje Critico
 * Contexto: matriz de tensiones. Cuenta cuantas celdas superan un umbral de sobretension.
 */
#include <stdio.h>

int cuentaCriticos(int n, int m, double mat[n][m], double umbral) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] > umbral) {
                contador = contador + 1;
            }
        }
    }
    return contador;
}

int main(void) {
    int n, m;
    double umbral;
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

    printf("Umbral critico de sobretension: ");
    scanf("%lf", &umbral);

    printf("Nodos que superan el umbral: %d\n", cuentaCriticos(n, m, mat, umbral));
    return 0;
}
