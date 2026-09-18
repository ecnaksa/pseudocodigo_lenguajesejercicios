/* Ejercicio 2 - Signo de un numero. */
#include <stdio.h>

int main(void) {
    int n;
    printf("Numero: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Positivo\n");
    } else if (n < 0) {
        printf("Negativo\n");
    } else {
        printf("Cero\n");
    }
    return 0;
}
