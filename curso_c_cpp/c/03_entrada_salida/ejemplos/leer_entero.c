/*
 * Leer un entero con scanf (ojo con el & ).
 * Prueba: printf "25\n" | ./prog
 */
#include <stdio.h>

int main(void) {
    int edad;
    printf("Ingresa tu edad: ");
    scanf("%d", &edad);                 // & = direccion de 'edad'
    printf("El proximo anio tendras %d\n", edad + 1);
    return 0;
}
