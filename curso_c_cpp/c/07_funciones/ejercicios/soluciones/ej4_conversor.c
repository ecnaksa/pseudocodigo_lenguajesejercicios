/* Ejercicio 4 - Conversor Celsius a Fahrenheit como funcion, con tabla. */
#include <stdio.h>

double aFahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

int main(void) {
    for (int c = 0; c <= 40; c += 10) {
        printf("%3d C = %6.1f F\n", c, aFahrenheit(c));
    }
    return 0;
}
