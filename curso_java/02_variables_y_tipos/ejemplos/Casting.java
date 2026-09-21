/*
 * Conversion de tipos: automatica (widening) y explicita (narrowing / division).
 */
public class Casting {
    public static void main(String[] args) {
        int i = 10;
        double d = i;                 // int -> double automatico
        System.out.println("int a double: " + d);   // 10.0

        double precio = 9.99;
        int entero = (int) precio;    // narrowing: se trunca
        System.out.println("double a int: " + entero);  // 9

        int a = 7, b = 2;
        System.out.println("7 / 2 entero: " + (a / b));            // 3
        System.out.println("7 / 2 real:   " + ((double) a / b));   // 3.5
    }
}
