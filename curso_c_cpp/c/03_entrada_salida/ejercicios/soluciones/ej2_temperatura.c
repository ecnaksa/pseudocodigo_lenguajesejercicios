/* Ejercicio 2 - Celsius a Fahrenheit. */
#include <stdio.h>

int main(void) {
    double celsius;
    printf("Temperatura en Celsius: ");
    scanf("%lf", &celsius);                    // %lf para leer double

    double fahrenheit = celsius * 9 / 5 + 32;
    printf("%.1f C = %.1f F\n", celsius, fahrenheit);
    return 0;
}
