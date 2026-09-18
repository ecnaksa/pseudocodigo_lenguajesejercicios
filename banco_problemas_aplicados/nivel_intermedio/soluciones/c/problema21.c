/*
 * Problema 21 - Pico Maximo y Su Indice Modular
 * Contexto: 20 muestras analogicas. Funcion "modular" que devuelve el valor pico maximo
 * Y su indice de muestreo. Como una funcion en C solo retorna UN valor, el indice se
 * entrega por REFERENCIA (puntero int *pos). (Ver teoria/01_devolver_varios_valores.md)
 */
#include <stdio.h>

double picoMaximo(double arr[], int tam, int *pos) {
    double mayor = arr[0];
    *pos = 0;                          /* *pos escribe en la variable de main */
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            *pos = i;
        }
    }
    return mayor;                      /* el valor se retorna normal */
}

int main(void) {
    int tam = 20;
    double arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Muestra %d: ", i);
        scanf("%lf", &arr[i]);
    }

    int posicion;
    double valor = picoMaximo(arr, tam, &posicion);   /* &posicion = su direccion */
    printf("Pico maximo: %.2f\n", valor);
    printf("Indice de muestreo: %d\n", posicion);
    return 0;
}
