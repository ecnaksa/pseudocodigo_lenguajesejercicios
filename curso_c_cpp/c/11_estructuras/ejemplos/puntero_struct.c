/*
 * Puntero a struct y el operador ->. La funcion modifica el original.
 */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;

void cumplirAnios(Persona *p) {
    p->edad = p->edad + 1;       // p->edad equivale a (*p).edad
}

int main(void) {
    Persona ana;
    strcpy(ana.nombre, "Ana");
    ana.edad = 20;

    cumplirAnios(&ana);          // pasamos la direccion
    printf("%s tiene ahora %d\n", ana.nombre, ana.edad);   // 21
    return 0;
}
