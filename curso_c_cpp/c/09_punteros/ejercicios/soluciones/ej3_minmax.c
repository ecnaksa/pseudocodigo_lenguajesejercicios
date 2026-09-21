/* Ejercicio 3 - Minimo y maximo devueltos por punteros. */
#include <stdio.h>

void minmax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void) {
    int a[6] = {23, 8, 45, 12, 4, 30};
    int menor, mayor;
    minmax(a, 6, &menor, &mayor);
    printf("min=%d, max=%d\n", menor, mayor);
    return 0;
}
