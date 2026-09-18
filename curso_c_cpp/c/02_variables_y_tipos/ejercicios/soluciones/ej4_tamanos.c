/* Ejercicio 4 - Tamanos de tipos y INT_MAX. */
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("sizeof(int)    = %zu\n", sizeof(int));
    printf("sizeof(long)   = %zu\n", sizeof(long));
    printf("sizeof(float)  = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("INT_MAX = %d\n", INT_MAX);
    return 0;
}
