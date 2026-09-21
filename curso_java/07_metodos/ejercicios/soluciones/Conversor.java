/* Ejercicio 4 - Conversor Celsius a Fahrenheit como metodo, con tabla. */
import java.util.Locale;

public class Conversor {
    static double aFahrenheit(double c) {
        return c * 9 / 5 + 32;
    }
    public static void main(String[] args) {
        for (int c = 0; c <= 40; c += 10) {
            System.out.printf(Locale.US, "%3d C = %6.1f F%n", c, aFahrenheit(c));
        }
    }
}
