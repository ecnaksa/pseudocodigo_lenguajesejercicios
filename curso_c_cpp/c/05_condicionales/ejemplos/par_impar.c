/*
 * if/else: decir si un numero es par o impar.
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Numero: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d es par\n", n);
    } else {
        printf("%d es impar\n", n);
    }
    return 0;
}
