/* Ejercicio 1 - Cuenta regresiva. */
#include <stdio.h>

int main(void) {
    int n;
    printf("Desde: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nDespegue!\n");
    return 0;
}
