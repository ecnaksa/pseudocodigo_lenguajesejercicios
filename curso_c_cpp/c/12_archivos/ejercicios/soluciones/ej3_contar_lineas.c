/* Ejercicio 3 - Contar lineas de un archivo con fgets. */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("numeros.txt", "r");
    if (f == NULL) {
        printf("No existe numeros.txt\n");
        return 1;
    }

    char linea[256];
    int lineas = 0;
    while (fgets(linea, sizeof(linea), f) != NULL) {
        lineas++;
    }
    fclose(f);

    printf("Lineas: %d\n", lineas);
    return 0;
}
