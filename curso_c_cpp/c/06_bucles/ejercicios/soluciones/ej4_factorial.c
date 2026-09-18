/* Ejercicio 4 - Factorial n! con long long. */
#include <stdio.h>

int main(void) {
    int n;
    printf("n: ");
    scanf("%d", &n);

    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    printf("%d! = %lld\n", n, fact);   // %lld para long long
    return 0;
}
