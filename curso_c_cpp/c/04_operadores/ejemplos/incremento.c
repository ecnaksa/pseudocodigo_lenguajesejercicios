/*
 * ++ y -- en forma prefija y postfija, y asignacion compuesta.
 */
#include <stdio.h>

int main(void) {
    int a = 5;
    printf("a++ imprime %d, ", a++);   // usa 5, luego a=6
    printf("y ahora a = %d\n", a);

    int b = 5;
    printf("++b imprime %d, ", ++b);   // incrementa antes: 6
    printf("y ahora b = %d\n", b);

    int total = 10;
    total += 5;    // 15
    total *= 2;    // 30
    printf("total = %d\n", total);
    return 0;
}
