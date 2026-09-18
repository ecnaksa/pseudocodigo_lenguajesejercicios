/* Ejercicio 2 - Maximo de tres enteros. */
#include <stdio.h>

int maximo3(int a, int b, int c) {
    int mayor = a;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;
    return mayor;
}

int main(void) {
    int a, b, c;
    printf("Tres enteros: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("El mayor es %d\n", maximo3(a, b, c));
    return 0;
}
