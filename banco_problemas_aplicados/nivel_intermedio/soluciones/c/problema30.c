/*
 * Problema 30 - Transposicion de Matriz de Admitancias
 * Contexto: analisis matricial de circuitos. Recibe una matriz N x M y devuelve su
 * transpuesta M x N:  Trans[j][i] = Mat[i][j].
 */
#include <stdio.h>

void transpone(int n, int m, double mat[n][m], double trans[m][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trans[j][i] = mat[i][j];    /* se intercambian los indices */
        }
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

    double trans[m][n];
    transpone(n, m, mat, trans);

    printf("Matriz transpuesta (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
