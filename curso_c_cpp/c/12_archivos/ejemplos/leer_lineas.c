/*
 * Leer un archivo linea por linea con fgets, y ademas parsear con fscanf.
 * Ejecuta primero el ejemplo escribir.c para crear notas.txt.
 */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("notas.txt", "r");   // "r" para leer (debe existir)
    if (f == NULL) {
        printf("No existe notas.txt (ejecuta antes escribir.c)\n");
        return 1;
    }

    char nombre[50];
    int nota;
    printf("Contenido:\n");
    while (fscanf(f, "%49s %d", nombre, &nota) == 2) {
        printf("  %s -> %d\n", nombre, nota);
    }

    fclose(f);
    return 0;
}
