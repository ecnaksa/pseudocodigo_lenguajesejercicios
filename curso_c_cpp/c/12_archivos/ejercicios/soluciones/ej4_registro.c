/* Ejercicio 4 - Anadir (append) una linea a registro.txt sin borrar lo anterior. */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("registro.txt", "a");   // "a" = append (agrega al final)
    if (f == NULL) return 1;

    fprintf(f, "Nueva entrada de registro\n");
    fclose(f);

    printf("Linea agregada a registro.txt (ejecutalo varias veces)\n");
    return 0;
}
