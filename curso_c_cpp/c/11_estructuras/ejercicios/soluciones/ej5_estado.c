/* Ejercicio 5 (reto) - enum de estados y su nombre como cadena. */
#include <stdio.h>

typedef enum { PENDIENTE, EN_PROGRESO, HECHO } Estado;

const char *nombreEstado(Estado e) {
    switch (e) {
        case PENDIENTE:   return "Pendiente";
        case EN_PROGRESO: return "En progreso";
        case HECHO:       return "Hecho";
        default:          return "Desconocido";
    }
}

int main(void) {
    Estado tarea = EN_PROGRESO;
    printf("Estado: %s\n", nombreEstado(tarea));
    return 0;
}
