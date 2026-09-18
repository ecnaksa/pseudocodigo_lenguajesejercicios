/*
 * Ejemplo 2 - Varios printf y secuencias de escape (\n salto de linea, \t tabulacion).
 */
#include <stdio.h>

int main(void) {
    printf("Aprendiendo C\n");
    printf("Linea 1\nLinea 2\n");     /* dos lineas en un solo printf */
    printf("Nombre:\tEdad:\n");       /* \t separa con una tabulacion */
    printf("Ana\t25\n");
    printf("Se imprime una comilla: \" y una barra: \\\n");
    return 0;
}
