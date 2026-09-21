/* geometria.c - implementacion del modulo. */
#include "geometria.h"

#define PI 3.14159265

double areaCirculo(double r) {
    return PI * r * r;
}

double areaRectangulo(double base, double altura) {
    return base * altura;
}
