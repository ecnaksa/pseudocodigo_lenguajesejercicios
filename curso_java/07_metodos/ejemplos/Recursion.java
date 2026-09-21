/*
 * Recursion: factorial y Fibonacci, cada una con su caso base.
 */
public class Recursion {

    static long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
    static int fibonacci(int n) {
        if (n < 2) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        System.out.println("factorial(5) = " + factorial(5));    // 120
        System.out.println("fibonacci(10) = " + fibonacci(10));  // 55
    }
}
