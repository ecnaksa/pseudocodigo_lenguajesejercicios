/*
 * Problema 17 - Desplazamiento Lineal de Buffer FIFO
 * void desplazaFIFO(double Arr[], int tam, double nueva)
 * Contexto: buffer de temperatura. Mover todos los registros una posicion a la derecha
 * (Arr[i] = Arr[i-1]) para dejar espacio a una nueva lectura en Arr[0]. La ultima se descarta.
 *
 * OJO: se recorre DESDE EL FINAL hacia el inicio; si se hiciera al reves se sobre-
 * escribirian los valores antes de copiarlos. (Ver teoria/05_desplazamiento_fifo_e_inversion_espejo.md)
 */
#include <stdio.h>

void desplazaFIFO(double arr[], int tam, double nueva) {
    for (int i = tam - 1; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = nueva;                  /* la nueva lectura entra al frente */
}

int main(void) {
    int tam;
    printf("Ingrese el tamano del buffer: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Registro %d: ", i);
        scanf("%lf", &arr[i]);
    }

    double nueva;
    printf("Nueva lectura a insertar: ");
    scanf("%lf", &nueva);

    desplazaFIFO(arr, tam, nueva);

    printf("Buffer tras el desplazamiento: ");
    for (int i = 0; i < tam; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
