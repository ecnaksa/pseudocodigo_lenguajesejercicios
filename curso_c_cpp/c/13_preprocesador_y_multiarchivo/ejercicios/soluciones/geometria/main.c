/* main.c - usa el modulo geometria. */
#include <stdio.h>
#include "geometria.h"

int main(void) {
    printf("Area circulo (r=2):        %.4f\n", areaCirculo(2.0));
    printf("Area rectangulo (3 x 4):   %.4f\n", areaRectangulo(3.0, 4.0));
    return 0;
}
