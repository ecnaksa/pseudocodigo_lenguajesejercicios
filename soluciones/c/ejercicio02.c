/*
 * Ejercicio 02 - Nivel Basico
 * int buscaMinimo(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa el valor minimo almacenado.
 */
#include <stdio.h>

/*
 * Se toma el primer elemento como minimo provisional y se recorre el resto:
 * cada vez que se encuentra un valor menor, se actualiza el minimo.
 */
int buscaMinimo(int arr[], int tam) {
    int min = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("El valor minimo es: %d\n", buscaMinimo(arr, tam));
    return 0;
}
