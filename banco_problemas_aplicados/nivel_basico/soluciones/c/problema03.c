/*
 * Problema 03 - Deteccion de Transitorios Impares
 * int cuentaImpares(int Arr[], int tam)
 * Contexto: analisis de ruido EM. Cuenta las muestras ubicadas en INDICES impares.
 *
 * OJO: aqui la condicion es sobre el INDICE (i % 2 != 0), no sobre el valor.
 * Por eso el contenido del arreglo no se usa: solo importa su posicion.
 * (Ver teoria/02_condicion_sobre_indice_vs_valor.md)
 */
#include <stdio.h>

int cuentaImpares(int arr[], int tam) {
    (void) arr;  /* el arreglo forma parte de la firma pedida, aunque no se lea su contenido */
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 != 0) {            /* i impar: 1, 3, 5, ... */
            contador = contador + 1;
        }
    }
    return contador;
}

int main(void) {
    int tam;
    printf("Ingrese el numero de muestras: ");
    scanf("%d", &tam);

    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Muestra %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Muestras en indices impares: %d\n", cuentaImpares(arr, tam));
    return 0;
}
