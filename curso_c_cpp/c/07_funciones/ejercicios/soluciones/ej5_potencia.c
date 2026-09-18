/* Ejercicio 5 (reto) - Potencia recursiva base^exp. */
#include <stdio.h>

long long potencia(int base, int exp) {
    if (exp == 0) return 1;                  // caso base
    return base * potencia(base, exp - 1);   // caso recursivo
}

int main(void) {
    int base, exp;
    printf("Base y exponente: ");
    scanf("%d %d", &base, &exp);
    printf("%d^%d = %lld\n", base, exp, potencia(base, exp));
    return 0;
}
