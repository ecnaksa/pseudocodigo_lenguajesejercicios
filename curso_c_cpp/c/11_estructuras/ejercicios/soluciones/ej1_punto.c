/* Ejercicio 1 - Distancia entre dos puntos. Compilar con -lm (al final). */
#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } Punto;

int main(void) {
    Punto a = {0.0, 0.0};
    Punto b = {3.0, 4.0};

    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dist = sqrt(dx * dx + dy * dy);

    printf("Distancia: %.2f\n", dist);    // 5.00
    return 0;
}
