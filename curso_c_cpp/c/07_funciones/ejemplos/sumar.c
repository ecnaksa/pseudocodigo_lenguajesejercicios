/*
 * Definir y usar funciones. Se muestran prototipos arriba y definiciones abajo.
 */
#include <stdio.h>

int sumar(int a, int b);           // prototipos
double areaCirculo(double radio);
void saludar(void);

int main(void) {
    saludar();
    printf("3 + 4 = %d\n", sumar(3, 4));
    printf("Area (r=2) = %.4f\n", areaCirculo(2.0));
    return 0;
}

int sumar(int a, int b) {
    return a + b;
}

double areaCirculo(double radio) {
    const double PI = 3.14159265;
    return PI * radio * radio;
}

void saludar(void) {
    printf("Bienvenido al ejemplo de funciones\n");
}
