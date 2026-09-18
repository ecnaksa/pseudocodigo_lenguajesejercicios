/* Ejercicio 3 - Total = precio * cantidad, con formato. */
#include <stdio.h>

int main(void) {
    double precio;
    int cantidad;
    printf("Precio: ");
    scanf("%lf", &precio);
    printf("Cantidad: ");
    scanf("%d", &cantidad);

    double total = precio * cantidad;
    printf("Total: %10.2f\n", total);          // ancho 10, 2 decimales
    return 0;
}
