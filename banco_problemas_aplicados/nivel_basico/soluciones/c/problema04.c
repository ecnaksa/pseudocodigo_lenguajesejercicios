/*
 * Problema 04 - Codigo de Error en Buffer
 * int buscaElemento(int Arr[], int x, int tam)
 * Contexto: registro de estados de microcontrolador. Devuelve la posicion del codigo x, o -1.
 */
#include <stdio.h>

int buscaElemento(int arr[], int x, int tam) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == x) {
            return i;                /* encontrado: se devuelve el indice de inmediato */
        }
    }
    return -1;                       /* no esta en el buffer */
}

int main(void) {
    int tam, x;
    printf("Ingrese el tamano del buffer: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Estado %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Ingrese el codigo de falla a buscar: ");
    scanf("%d", &x);

    int pos = buscaElemento(arr, x, tam);
    if (pos < 0) {
        printf("El codigo %d no aparece en el buffer.\n", x);
    } else {
        printf("El codigo %d esta en la posicion: %d\n", x, pos);
    }
    return 0;
}
