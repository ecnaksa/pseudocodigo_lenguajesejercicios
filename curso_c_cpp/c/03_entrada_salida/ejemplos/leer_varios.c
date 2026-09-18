/*
 * Leer varios valores, incluido un double (%lf) y un char (" %c").
 * Prueba: printf "3 4\nX\n" | ./prog
 */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Dos enteros: ");
    scanf("%d %d", &a, &b);
    printf("Suma = %d\n", a + b);

    char grado;
    printf("Una letra de grado: ");
    scanf(" %c", &grado);              // el espacio evita capturar el '\n' pendiente
    printf("Grado: %c\n", grado);
    return 0;
}
