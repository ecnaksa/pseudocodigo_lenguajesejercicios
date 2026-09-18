/*
 * else if encadenado: convertir una nota numerica a una letra.
 */
#include <stdio.h>

int main(void) {
    int nota;
    printf("Nota (0-100): ");
    scanf("%d", &nota);

    if (nota >= 90) {
        printf("A - Excelente\n");
    } else if (nota >= 80) {
        printf("B - Muy bien\n");
    } else if (nota >= 70) {
        printf("C - Aprobado\n");
    } else if (nota >= 60) {
        printf("D - Justo\n");
    } else {
        printf("F - Reprobado\n");
    }
    return 0;
}
