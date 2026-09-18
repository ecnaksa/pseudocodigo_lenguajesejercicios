/*
 * while con centinela: sumar numeros hasta que llegue un 0.
 * Prueba: printf "3\n5\n2\n0\n" | ./prog   -> Suma: 10
 */
#include <stdio.h>

int main(void) {
    int n, suma = 0;
    printf("Escribe numeros (0 para terminar):\n");
    while (scanf("%d", &n) == 1 && n != 0) {
        suma += n;
    }
    printf("Suma: %d\n", suma);
    return 0;
}
