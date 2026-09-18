/* Ejercicio 2 - Suma de 1 a N. */
#include <stdio.h>

int main(void) {
    int n;
    printf("N: ");
    scanf("%d", &n);

    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    printf("1 + ... + %d = %d\n", n, suma);
    return 0;
}
