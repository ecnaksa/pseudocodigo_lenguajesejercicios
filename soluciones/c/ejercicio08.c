/*
 * Ejercicio 08 - Nivel Intermedio
 * Almacenar 5 numeros enteros en un arreglo, calcular y desplegar su promedio,
 * determinar cuantos son mayores que el promedio y desplegar esos valores.
 */
#include <stdio.h>

void promedioMayores(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }

    /*
     * Para obtener un promedio con decimales se necesita division real.
     * Al convertir 'suma' a double, la division deja de ser entera.
     */
    double promedio = (double) suma / tam;
    printf("Promedio: %.2f\n", promedio);

    int mayores = 0;
    printf("Valores mayores al promedio:\n");
    for (int i = 0; i < tam; i++) {
        if (arr[i] > promedio) {
            mayores = mayores + 1;
            printf("%d\n", arr[i]);
        }
    }
    printf("Cantidad de elementos mayores al promedio: %d\n", mayores);
}

int main(void) {
    int tam = 5;
    int arr[tam];
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &arr[i]);
    }
    promedioMayores(arr, tam);
    return 0;
}
