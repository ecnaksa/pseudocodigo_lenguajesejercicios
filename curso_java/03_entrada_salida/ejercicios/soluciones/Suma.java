/* Ejercicio 1 - Suma de dos numeros. */
import java.util.Scanner;

public class Suma {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Primer numero: ");
        int a = sc.nextInt();
        System.out.print("Segundo numero: ");
        int b = sc.nextInt();
        System.out.println("Suma: " + (a + b));
        sc.close();
    }
}
