/* Ejercicio 3 - Producto mas caro de un arreglo de structs. */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[30];
    double precio;
} Producto;

int main(void) {
    Producto lista[3] = {
        {"Cafe", 3.50},
        {"Pan", 1.20},
        {"Leche", 4.00}
    };

    int idxCaro = 0;
    for (int i = 1; i < 3; i++) {
        if (lista[i].precio > lista[idxCaro].precio) idxCaro = i;
    }
    printf("El mas caro: %s (%.2f)\n", lista[idxCaro].nombre, lista[idxCaro].precio);
    return 0;
}
