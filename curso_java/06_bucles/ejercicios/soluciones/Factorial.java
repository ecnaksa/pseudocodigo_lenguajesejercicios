/* Ejercicio 4 - Factorial n! con long. */
import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("n: ");
        int n = sc.nextInt();

        long fact = 1;
        for (int i = 2; i <= n; i++) fact *= i;
        System.out.println(n + "! = " + fact);
        sc.close();
    }
}
