/* Ejercicio 2 - Suma de 1 a N. */
import java.util.Scanner;

public class SumaN {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("N: ");
        int n = sc.nextInt();

        int suma = 0;
        for (int i = 1; i <= n; i++) suma += i;
        System.out.println("1 + ... + " + n + " = " + suma);
        sc.close();
    }
}
