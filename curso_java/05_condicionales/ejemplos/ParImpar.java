/*
 * if/else: decir si un numero es par o impar.
 */
import java.util.Scanner;

public class ParImpar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero: ");
        int n = sc.nextInt();

        if (n % 2 == 0) {
            System.out.println(n + " es par");
        } else {
            System.out.println(n + " es impar");
        }
        sc.close();
    }
}
