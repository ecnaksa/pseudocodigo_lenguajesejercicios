/*
 * Formato de salida con printf.
 */
import java.util.Locale;

public class FormatoPrintf {
    public static void main(String[] args) {
        double pi = 3.14159265;

        System.out.printf("Por defecto: %f%n", pi);
        System.out.printf(Locale.US, "2 decimales: %.2f%n", pi);   // 3.14
        System.out.printf("Entero:      %d%n", 42);
        System.out.printf("Alineado:   [%-8s][%5d]%n", "Ana", 25);
        System.out.printf("Booleano:    %b%n", 5 > 3);
    }
}
