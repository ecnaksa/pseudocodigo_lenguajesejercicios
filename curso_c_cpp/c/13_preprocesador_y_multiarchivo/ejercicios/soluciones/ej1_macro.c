/* Ejercicio 1 - Macro con parametros (ojo con los parentesis). */
#include <stdio.h>

#define A_FAHRENHEIT(c) ((c) * 9.0 / 5.0 + 32.0)

int main(void) {
    printf("%6.1f C = %6.1f F\n",   0.0, A_FAHRENHEIT(0));
    printf("%6.1f C = %6.1f F\n",  25.0, A_FAHRENHEIT(25));
    printf("%6.1f C = %6.1f F\n", 100.0, A_FAHRENHEIT(100));
    return 0;
}
