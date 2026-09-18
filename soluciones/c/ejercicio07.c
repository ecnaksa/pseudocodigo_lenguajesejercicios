/*
 * Ejercicio 07 - Nivel Intermedio
 * Almacenar 10 numeros enteros en un vector. Imprimir cuantos son ceros,
 * cuantos negativos y cuantos positivos. Ademas la suma de los negativos
 * y la suma de los positivos.
 */
#include <stdio.h>

/*
 * La funcion no devuelve un valor (void): su trabajo es analizar el arreglo
 * e imprimir directamente los resultados.
 */
void analizarArreglo(int arr[], int tam) {
    int ceros = 0, pos = 0, neg = 0, spos = 0, sneg = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 0) {
            ceros = ceros + 1;
        } else if (arr[i] < 0) {
            neg = neg + 1;
            sneg = sneg + arr[i];
        } else {
            pos = pos + 1;
            spos = spos + arr[i];
        }
    }
    printf("Cantidad de ceros: %d\n", ceros);
    printf("Cantidad de positivos: %d\n", pos);
    printf("Cantidad de negativos: %d\n", neg);
    printf("Suma de los positivos: %d\n", spos);
    printf("Suma de los negativos: %d\n", sneg);
}

int main(void) {
    int tam = 10;
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }
    analizarArreglo(arr, tam);
    return 0;
}
