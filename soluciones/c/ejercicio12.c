/*
 * Ejercicio 12 - Nivel Avanzado
 * void invierteArreglo(int Arr[], int tam)
 * Modifica el orden de los elementos de manera que queden invertidos.
 */
#include <stdio.h>

/*
 * Se intercambian los extremos hacia el centro: el primero con el ultimo,
 * el segundo con el penultimo, etc. Basta recorrer hasta la mitad (tam/2).
 * 'aux' guarda temporalmente un valor durante el intercambio.
 */
void invierteArreglo(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];
        arr[i] = arr[tam - 1 - i];
        arr[tam - 1 - i] = aux;
    }
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

    invierteArreglo(arr, tam);

    printf("El nuevo arreglo (invertido) es:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
