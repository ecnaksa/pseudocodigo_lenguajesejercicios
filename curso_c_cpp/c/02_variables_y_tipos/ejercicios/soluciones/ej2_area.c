/* Ejercicio 2 - Area de un circulo. */
#include <stdio.h>

int main(void) {
    const double PI = 3.14159;
    double radio = 5.0;
    double area = PI * radio * radio;

    printf("Radio: %.2f\n", radio);
    printf("Area:  %.4f\n", area);
    return 0;
}
