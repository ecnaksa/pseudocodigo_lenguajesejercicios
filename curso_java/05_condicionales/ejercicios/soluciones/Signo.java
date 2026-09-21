/* Ejercicio 2 - Signo de un numero. */
import java.util.Scanner;

public class Signo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero: ");
        int n = sc.nextInt();

        if (n > 0) {
            System.out.println("Positivo");
        } else if (n < 0) {
            System.out.println("Negativo");
        } else {
            System.out.println("Cero");
        }
        sc.close();
    }
}
