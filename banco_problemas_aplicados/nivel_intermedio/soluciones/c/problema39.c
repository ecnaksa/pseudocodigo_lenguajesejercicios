/*
 * Problema 39 - Analisis de Simetria Espectral Basica
 * bool esSimetrico(double Arr[], int n)
 * Contexto: comprobar si los primeros N/2 elementos coinciden de forma inversa con los
 * ultimos N/2, es decir, si el vector es simetrico (palindromo): Arr[i] == Arr[n-1-i].
 */
#include <stdio.h>
#include <stdbool.h>

bool esSimetrico(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n;
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%lf", &arr[i]);
    }

    if (esSimetrico(arr, n)) {
        printf("El vector es simetrico (mitades opuestas coinciden).\n");
    } else {
        printf("El vector NO es simetrico.\n");
    }
    return 0;
}
