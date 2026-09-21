/* Ejercicio 1 - Metodo cuadrado. */
public class Cuadrado {
    static int cuadrado(int n) {
        return n * n;
    }
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            System.out.println(i + " al cuadrado = " + cuadrado(i));
        }
    }
}
