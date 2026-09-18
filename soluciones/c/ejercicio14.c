/*
 * Ejercicio 14 - Nivel Avanzado
 * void ordenaBurbuja(int Arr[], int tam)
 * Implementa el metodo de la burbuja para ordenar el arreglo de forma ascendente.
 */
#include <stdio.h>

/*
 * Metodo de la burbuja: se comparan elementos adyacentes y, si estan en el
 * orden equivocado, se intercambian. En cada pasada el mayor valor "sube"
 * hasta el final, por eso el bucle interno llega solo hasta tam-1-i.
 */
void ordenaBurbuja(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int f = 0; f < tam - 1 - i; f++) {
            if (arr[f] > arr[f + 1]) {
                int aux = arr[f];
                arr[f] = arr[f + 1];
                arr[f + 1] = aux;
            }
        }
    }
}

int main(void) {
    int tam = 5;
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    ordenaBurbuja(arr, tam);

    printf("El arreglo ordenado es: ");
    for (int i = 0; i < tam; i++) {
        /* "Escribir sin saltar": se imprime sin salto de linea (no hay \n). */
        printf("%d ", arr[i]);
    }
    printf("\n");   /* Un unico salto de linea al final. */
    return 0;
}
