/*
 * Tipos basicos: int, double, char. Observa como un char se puede ver como numero.
 */
#include <stdio.h>

int main(void) {
    int cantidad = 5;
    double precio = 2.50;
    char letra = 'C';

    printf("Cantidad: %d\n", cantidad);
    printf("Precio:   %f\n", precio);
    printf("Letra:    %c  (codigo ASCII %d)\n", letra, letra);

    const double PI = 3.14159;
    printf("PI = %f\n", PI);
    return 0;
}
