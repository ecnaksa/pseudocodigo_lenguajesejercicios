/*
 * Division entera vs division real, y el casting (double).
 */
#include <stdio.h>

int main(void) {
    int a = 7, b = 2;

    printf("Division entera 7/2 = %d\n", a / b);          // 3

    double real = (double) a / b;                          // se convierte 'a' antes de dividir
    printf("Division real   7/2 = %f\n", real);            // 3.500000

    /* Cuidado: convertir DESPUES de dividir no sirve */
    double tarde = (double)(a / b);
    printf("(double)(a/b)      = %f\n", tarde);            // 3.000000  (ya se perdio el decimal)
    return 0;
}
