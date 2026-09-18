/* Ejercicio 4 - Vocal o consonante con switch (agrupando casos). */
#include <stdio.h>

int main(void) {
    char letra;
    printf("Una letra minuscula: ");
    scanf(" %c", &letra);

    switch (letra) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Es vocal\n");
            break;
        default:
            printf("Es consonante\n");
    }
    return 0;
}
