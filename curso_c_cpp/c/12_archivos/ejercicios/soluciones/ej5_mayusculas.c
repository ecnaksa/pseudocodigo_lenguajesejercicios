/* Ejercicio 5 (reto) - Copiar convirtiendo a mayusculas, caracter a caracter. */
#include <stdio.h>
#include <ctype.h>      // toupper

int main(void) {
    FILE *entrada = fopen("numeros.txt", "r");
    if (entrada == NULL) {
        printf("No existe numeros.txt\n");
        return 1;
    }
    FILE *salida = fopen("salida.txt", "w");
    if (salida == NULL) { fclose(entrada); return 1; }

    int c;                                   // fgetc devuelve int (para poder dar EOF)
    while ((c = fgetc(entrada)) != EOF) {
        fputc(toupper(c), salida);           // convierte letras a mayuscula
    }

    fclose(entrada);
    fclose(salida);
    printf("Generado salida.txt en mayusculas\n");
    return 0;
}
