/* Ejercicio 1 - Mayor de dos numeros. */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    int mayor = (a > b) ? a : b;         // ternario
    printf("El mayor es %d\n", mayor);
    return 0;
}
