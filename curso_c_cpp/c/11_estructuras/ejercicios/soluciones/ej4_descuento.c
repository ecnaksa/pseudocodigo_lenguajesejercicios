/* Ejercicio 4 - Modificar el precio a traves de un puntero a struct. */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[30];
    double precio;
} Producto;

void aplicarDescuento(Producto *p, double pct) {
    p->precio = p->precio * (1.0 - pct / 100.0);
}

int main(void) {
    Producto cafe = {"Cafe", 10.0};
    aplicarDescuento(&cafe, 20.0);       // 20% de descuento
    printf("%s cuesta ahora %.2f\n", cafe.nombre, cafe.precio);   // 8.00
    return 0;
}
