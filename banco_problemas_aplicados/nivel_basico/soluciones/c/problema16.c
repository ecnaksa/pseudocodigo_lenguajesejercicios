/*
 * Problema 16 - Busqueda de Primer Flanco de Subida
 * int buscaFlanco(double Arr[], int tam)
 * Contexto: vector bipolar de voltajes. Hallar el primer indice i donde la senal cruza
 * de negativo a positivo:  Arr[i] < 0  Y  Arr[i+1] >= 0. Devuelve i o -1.
 *
 * OJO: como se usa Arr[i+1], el bucle llega solo hasta tam-2 (i < tam-1) para no salirse.
 */
#include <stdio.h>

int buscaFlanco(double arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] < 0 && arr[i + 1] >= 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Voltaje %d (V): ", i);
        scanf("%lf", &arr[i]);
    }

    int idx = buscaFlanco(arr, tam);
    if (idx < 0) {
        printf("No se detecto ningun flanco de subida.\n");
    } else {
        printf("Primer flanco de subida entre los indices %d y %d.\n", idx, idx + 1);
    }
    return 0;
}
