/* Ejercicio 1 - Cuenta regresiva. */
import java.util.Scanner;

public class Regresiva {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Desde: ");
        int n = sc.nextInt();

        for (int i = n; i >= 1; i--) {
            System.out.print(i + " ");
        }
        System.out.println("\nDespegue!");
        sc.close();
    }
}
