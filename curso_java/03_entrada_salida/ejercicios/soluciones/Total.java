/* Ejercicio 3 - Total = precio * cantidad con formato. */
import java.util.Scanner;
import java.util.Locale;

public class Total {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Precio: ");
        double precio = sc.nextDouble();
        System.out.print("Cantidad: ");
        int cantidad = sc.nextInt();

        System.out.printf(Locale.US, "Total: %.2f%n", precio * cantidad);
        sc.close();
    }
}
