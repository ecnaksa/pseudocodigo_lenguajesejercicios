/*
 * Problema 07 - Clasificador de Polaridad AC
 * Contexto: 10 lecturas de tension. Contar ceros exactos, positivos y negativos,
 * mostrando ademas la suma de positivos y la suma de negativos.
 */
#include <stdio.h>

void clasificaPolaridad(double arr[], int tam) {
    int ceros = 0, pos = 0, neg = 0;
    double spos = 0.0, sneg = 0.0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 0.0) {
            ceros = ceros + 1;
        } else if (arr[i] > 0.0) {
            pos = pos + 1;
            spos = spos + arr[i];
        } else {
            neg = neg + 1;
            sneg = sneg + arr[i];
        }
    }
    printf("Ceros exactos: %d\n", ceros);
    printf("Positivos: %d  (suma = %.2f)\n", pos, spos);
    printf("Negativos: %d  (suma = %.2f)\n", neg, sneg);
}

int main(void) {
    int tam = 10;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Lectura de tension %d (V): ", i);
        scanf("%lf", &arr[i]);
    }
    clasificaPolaridad(arr, tam);
    return 0;
}
