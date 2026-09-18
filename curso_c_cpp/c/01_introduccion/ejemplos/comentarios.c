/*
 * Ejemplo 3 - Comentarios de una linea y de varias lineas.
 * El compilador IGNORA los comentarios; son para las personas.
 */
#include <stdio.h>

int main(void) {
    // Esto es un comentario de una sola linea.
    printf("Primer mensaje\n");

    /* Esto es un comentario
       que ocupa varias lineas. */
    printf("Segundo mensaje\n");

    printf("Fin\n");   // tambien se puede comentar al final de una linea
    return 0;
}
