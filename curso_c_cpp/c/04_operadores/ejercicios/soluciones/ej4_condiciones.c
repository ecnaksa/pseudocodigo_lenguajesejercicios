/* Ejercicio 4 - Evaluar condiciones (resultado 1/0). */
#include <stdio.h>

int main(void) {
    int edad;
    printf("Edad: ");
    scanf("%d", &edad);

    printf("edad >= 18            -> %d\n", edad >= 18);
    printf("18 <= edad <= 65      -> %d\n", edad >= 18 && edad <= 65);
    printf("edad < 12 O edad > 65 -> %d\n", edad < 12 || edad > 65);
    return 0;
}
