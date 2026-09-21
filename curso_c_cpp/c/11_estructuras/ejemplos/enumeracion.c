/*
 * enum: constantes con nombre para dias de la semana.
 */
#include <stdio.h>

typedef enum { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO } Dia;

int main(void) {
    Dia hoy = SABADO;

    printf("hoy vale %d\n", hoy);          // 5 (SABADO es el sexto, base 0)
    if (hoy == SABADO || hoy == DOMINGO) {
        printf("Es fin de semana\n");
    } else {
        printf("Es dia laboral\n");
    }
    return 0;
}
