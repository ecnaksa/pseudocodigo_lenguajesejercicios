/*
 * Ejercicio 11 - Nivel Intermedio
 * Llenar un vector de 20 elementos e imprimir la posicion y el valor del mayor.
 * (Se supone que todos los elementos son diferentes.)
 */
#include <stdio.h>

void encontrarMayor(int arr[], int tam) {
    int mayor = arr[0];
    int posicion = 0;
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            posicion = i;
        }
    }
    printf("El elemento mayor es: %d\n", mayor);
    printf("Se encuentra en la posicion: %d\n", posicion);
}

int main(void) {
    int tam = 20;
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }
    encontrarMayor(arr, tam);
    return 0;
}
