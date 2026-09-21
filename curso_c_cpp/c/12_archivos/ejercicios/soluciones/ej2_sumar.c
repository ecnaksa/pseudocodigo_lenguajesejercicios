/* Ejercicio 2 - Sumar los numeros de numeros.txt. */
#include <stdio.h>

int main(void) {
    FILE *f = fopen("numeros.txt", "r");
    if (f == NULL) {
        printf("No existe numeros.txt\n");
        return 1;
    }

    int n, suma = 0;
    while (fscanf(f, "%d", &n) == 1) {
        suma += n;
    }
    fclose(f);

    printf("Suma: %d\n", suma);
    return 0;
}
