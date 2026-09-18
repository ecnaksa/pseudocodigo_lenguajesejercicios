/* Ejercicio 3 - Intercambiar dos variables con una temporal. */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("Antes:   a=%d, b=%d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("Despues: a=%d, b=%d\n", a, b);
    return 0;
}
