/*
 * struct con typedef, inicializacion y arreglo de estructuras.
 */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    double promedio;
} Estudiante;

int main(void) {
    Estudiante grupo[3] = {
        {"Ana", 20, 8.5},
        {"Luis", 22, 7.8},
        {"Sara", 19, 9.1}
    };

    for (int i = 0; i < 3; i++) {
        printf("%-6s edad %d, promedio %.1f\n",
               grupo[i].nombre, grupo[i].edad, grupo[i].promedio);
    }
    return 0;
}
