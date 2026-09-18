/* Ejercicio 3 - Funcion esPrimo y lista de primos hasta 30. */
#include <stdio.h>

int esPrimo(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) {   // basta probar divisores hasta la raiz
        if (n % d == 0) return 0;        // tiene un divisor: no es primo
    }
    return 1;
}

int main(void) {
    printf("Primos hasta 30: ");
    for (int i = 2; i <= 30; i++) {
        if (esPrimo(i)) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
