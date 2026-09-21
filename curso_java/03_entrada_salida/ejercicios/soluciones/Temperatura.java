/* Ejercicio 2 - Celsius a Fahrenheit. */
import java.util.Scanner;
import java.util.Locale;

public class Temperatura {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Grados Celsius: ");
        double c = sc.nextDouble();

        double f = c * 9 / 5 + 32;
        System.out.printf(Locale.US, "%.1f C = %.1f F%n", c, f);
        sc.close();
    }
}
