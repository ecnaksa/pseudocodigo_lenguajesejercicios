/*
 * Escribir texto en un archivo con fprintf. Crea "notas.txt".
 */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("notas.txt", "w");   // "w" crea/vacia el archivo
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    fprintf(f, "Ana %d\n", 90);
    fprintf(f, "Luis %d\n", 85);
    fprintf(f, "Sara %d\n", 95);

    fclose(f);                            // cerrar SIEMPRE
    printf("Archivo notas.txt escrito.\n");
    return 0;
}
