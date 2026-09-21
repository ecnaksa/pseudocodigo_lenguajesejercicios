/*
 * Cadenas: %s, strlen, strcpy, strcat, strcmp.
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char nombre[] = "Ana";
    printf("Nombre: %s (largo %zu)\n", nombre, strlen(nombre));

    char saludo[50];
    strcpy(saludo, "Hola, ");        // copiar
    strcat(saludo, nombre);          // concatenar
    strcat(saludo, "!");
    printf("%s\n", saludo);          // Hola, Ana!

    if (strcmp(nombre, "Ana") == 0) {
        printf("El nombre es Ana\n");
    }
    return 0;
}
