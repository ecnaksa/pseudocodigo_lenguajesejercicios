/*
 * Problema 26 - Desplazamiento Circular de Muestras
 * void rotaDerecha(double Arr[], int tam, int k)
 * Contexto: simulacion de retardos. Rotacion ciclica hacia la derecha por K posiciones:
 * el elemento de la posicion i pasa a la posicion (i + k) % tam. Lo que sale por la derecha
 * reingresa por la izquierda. (Ver teoria/03_transformaciones_de_vector.md)
 */
#include <stdio.h>

void rotaDerecha(double arr[], int tam, int k) {
    k = k % tam;                        /* si k >= tam, la rotacion se repite */
    double aux[tam];
    for (int i = 0; i < tam; i++) {
        aux[(i + k) % tam] = arr[i];    /* indice circular con modulo */
    }
    for (int i = 0; i < tam; i++) {
        arr[i] = aux[i];                /* copiar el resultado de vuelta */
    }
}

int main(void) {
    int tam, k;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &tam);

    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Muestra %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("Ingrese K (posiciones a rotar a la derecha): ");
    scanf("%d", &k);

    rotaDerecha(arr, tam, k);

    printf("Buffer desplazado: ");
    for (int i = 0; i < tam; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}
