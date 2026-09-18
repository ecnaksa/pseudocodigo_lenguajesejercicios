/* Ejercicio 5 (reto) - Caracter y su codigo ASCII. */
#include <stdio.h>

int main(void) {
    char letra = 'Z';
    printf("Caracter: %c\n", letra);
    printf("Codigo ASCII: %d\n", letra);
    printf("El siguiente caracter es: %c\n", letra + 1);   // 'Z'+1 = '[' (codigo 91)
    return 0;
}
