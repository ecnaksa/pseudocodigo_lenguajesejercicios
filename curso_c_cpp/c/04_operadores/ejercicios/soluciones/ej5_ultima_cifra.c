/* Ejercicio 5 (reto) - Ultima cifra y numero sin ella. */
#include <stdio.h>

int main(void) {
    int n;
    printf("Numero: ");
    scanf("%d", &n);

    printf("Ultima cifra: %d\n", n % 10);
    printf("Sin la ultima cifra: %d\n", n / 10);
    return 0;
}
