/* Ejercicio 1 - Guardar los numeros 1..10 en numeros.txt. */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("numeros.txt", "w");
    if (f == NULL) return 1;

    for (int i = 1; i <= 10; i++) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
    printf("Escrito numeros.txt\n");
    return 0;
}
