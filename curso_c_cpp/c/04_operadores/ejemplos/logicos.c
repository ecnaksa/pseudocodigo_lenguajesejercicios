/*
 * Operadores relacionales y logicos. En C: 1 = verdadero, 0 = falso.
 */
#include <stdio.h>

int main(void) {
    int edad = 20;
    int tieneEntrada = 1;

    printf("edad >= 18: %d\n", edad >= 18);            // 1
    printf("edad == 30: %d\n", edad == 30);            // 0
    printf("mayor Y con entrada: %d\n", edad >= 18 && tieneEntrada);  // 1
    printf("menor O con entrada: %d\n", edad < 18 || tieneEntrada);   // 1
    printf("NO tiene entrada: %d\n", !tieneEntrada);   // 0
    return 0;
}
