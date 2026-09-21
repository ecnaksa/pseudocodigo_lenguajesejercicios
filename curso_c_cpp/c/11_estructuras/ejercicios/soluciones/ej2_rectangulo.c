/* Ejercicio 2 - Area de un rectangulo (struct pasada por valor a una funcion). */
#include <stdio.h>

typedef struct { double base, altura; } Rectangulo;

double area(Rectangulo r) {
    return r.base * r.altura;
}

int main(void) {
    Rectangulo r = {4.0, 3.0};
    printf("Area: %.2f\n", area(r));   // 12.00
    return 0;
}
