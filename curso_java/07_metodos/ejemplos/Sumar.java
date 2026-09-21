/*
 * Definir y usar metodos static. Incluye sobrecarga.
 */
public class Sumar {

    static int sumar(int a, int b) {
        return a + b;
    }
    static double areaCirculo(double radio) {
        final double PI = 3.14159265;
        return PI * radio * radio;
    }
    static void saludar(String nombre) {
        System.out.println("Hola, " + nombre);
    }

    public static void main(String[] args) {
        saludar("Java");
        System.out.println("3 + 4 = " + sumar(3, 4));
        System.out.printf("Area (r=2) = %.4f%n", areaCirculo(2.0));
    }
}
