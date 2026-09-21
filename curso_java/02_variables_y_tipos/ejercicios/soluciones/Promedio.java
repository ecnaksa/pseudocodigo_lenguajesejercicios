/* Ejercicio 3 - Promedio de tres enteros con decimales. */
public class Promedio {
    public static void main(String[] args) {
        int a = 7, b = 8, c = 10;
        int suma = a + b + c;

        double promedio = (double) suma / 3;   // (double) fuerza division real

        System.out.println("Suma: " + suma);
        System.out.println("Promedio: " + promedio);
    }
}
