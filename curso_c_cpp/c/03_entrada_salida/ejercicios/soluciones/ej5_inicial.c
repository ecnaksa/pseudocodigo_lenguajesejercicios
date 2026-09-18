/* Ejercicio 5 (reto) - Leer edad (int) y luego inicial (char). */
#include <stdio.h>

int main(void) {
    int edad;
    char inicial;

    printf("Edad: ");
    scanf("%d", &edad);
    printf("Inicial de tu nombre: ");
    scanf(" %c", &inicial);              // espacio antes de %c

    printf("Inicial %c, edad %d\n", inicial, edad);
    return 0;
}
