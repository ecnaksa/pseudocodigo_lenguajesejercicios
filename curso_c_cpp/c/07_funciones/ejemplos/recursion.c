/*
 * Recursion: factorial y Fibonacci. Cada una tiene su caso base.
 */
#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) return 1;                  // caso base
    return n * factorial(n - 1);           // caso recursivo
}

int fibonacci(int n) {
    if (n < 2) return n;                    // fib(0)=0, fib(1)=1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    printf("factorial(5) = %lld\n", factorial(5));   // 120
    printf("fibonacci(10) = %d\n", fibonacci(10));    // 55
    return 0;
}
