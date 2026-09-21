/*
 * Copiar un archivo de texto en otro, linea por linea.
 * Uso conceptual: crea "notas.txt" con escribir.c y este genera "copia.txt".
 */
#include <stdio.h>

int main(void) {
    FILE *entrada = fopen("notas.txt", "r");
    if (entrada == NULL) {
        printf("No existe notas.txt\n");
        return 1;
    }
    FILE *salida = fopen("copia.txt", "w");
    if (salida == NULL) {
        fclose(entrada);
        return 1;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), entrada) != NULL) {
        fputs(linea, salida);            // escribe la linea tal cual
    }

    fclose(entrada);
    fclose(salida);
    printf("Copiado notas.txt -> copia.txt\n");
    return 0;
}
