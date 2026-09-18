/* Ejercicio 5 (reto) - Calculadora simple con switch. */
#include <stdio.h>

int main(void) {
    double a, b;
    char op;
    printf("Primer numero: ");
    scanf("%lf", &a);
    printf("Operador (+ - * /): ");
    scanf(" %c", &op);
    printf("Segundo numero: ");
    scanf("%lf", &b);

    switch (op) {
        case '+':
            printf("%.2f\n", a + b);
            break;
        case '-':
            printf("%.2f\n", a - b);
            break;
        case '*':
            printf("%.2f\n", a * b);
            break;
        case '/':
            if (b != 0) {
                printf("%.2f\n", a / b);
            } else {
                printf("Error: division entre cero\n");
            }
            break;
        default:
            printf("Operador desconocido\n");
    }
    return 0;
}
