/* Ejercicio 4 - Area y perimetro de un rectangulo. */
#include <stdio.h>

int main(void) {
    int base, altura;
    printf("Base: ");
    scanf("%d", &base);
    printf("Altura: ");
    scanf("%d", &altura);

    printf("Area: %d\n", base * altura);
    printf("Perimetro: %d\n", 2 * (base + altura));
    return 0;
}
