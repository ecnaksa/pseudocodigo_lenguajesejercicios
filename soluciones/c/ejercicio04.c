/*
 * Ejercicio 04 - Nivel Basico
 * int buscaElemento(int Arr[], int x, int tam)
 * Busca el valor x dentro del arreglo y regresa su posicion,
 * o un valor indicativo (-1) si no se encuentra.
 */
#include <stdio.h>

/*
 * Busqueda lineal: se recorre el arreglo y, en cuanto se encuentra x,
 * se devuelve su indice. Si el bucle termina sin encontrarlo, se regresa -1.
 */
int buscaElemento(int arr[], int x, int tam) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int tam, x;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &x);

    int pos = buscaElemento(arr, x, tam);
    if (pos < 0) {
        printf("No existe elemento coincidente.\n");
    } else {
        printf("La posicion del elemento es: %d\n", pos);
    }
    return 0;
}
