/* Ejercicio 2 - Descomponer segundos en minutos y segundos. */
#include <stdio.h>

int main(void) {
    int total;
    printf("Segundos: ");
    scanf("%d", &total);

    int minutos = total / 60;
    int segundos = total % 60;
    printf("%d segundos = %d min y %d s\n", total, minutos, segundos);
    return 0;
}
