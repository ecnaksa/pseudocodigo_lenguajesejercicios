/*
 * Operadores aritmeticos, con enfasis en / (division) y % (residuo).
 */
#include <stdio.h>

int main(void) {
    int a = 17, b = 5;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d  (division entera)\n", a, b, a / b);
    printf("%d %% %d = %d  (residuo)\n", a, b, a % b);

    /* Precedencia: * antes que + */
    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);       // 14
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);   // 20
    return 0;
}
