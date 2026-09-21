/* Ejercicio 1 - Residuo entre 2. */
import java.util.Scanner;

public class ParResiduo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero: ");
        int n = sc.nextInt();
        System.out.println("n % 2 = " + (n % 2));
        sc.close();
    }
}
