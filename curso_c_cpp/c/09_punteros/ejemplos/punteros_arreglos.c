/*
 * Relacion entre punteros y arreglos: a[i] == *(a + i).
 */
#include <stdio.h>

int main(void) {
    int a[4] = {10, 20, 30, 40};
    int *p = a;               // p apunta a a[0]

    for (int i = 0; i < 4; i++) {
        // dos formas equivalentes de acceder al elemento i:
        printf("a[%d]=%d  *(p+%d)=%d\n", i, a[i], i, *(p + i));
    }
    return 0;
}
