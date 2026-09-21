/*
 * Constantes con final y limites de int.
 */
public class Constantes {
    public static void main(String[] args) {
        final double PI = 3.14159;
        final int MAX_INTENTOS = 3;

        double radio = 2.0;
        System.out.println("Area = " + (PI * radio * radio));
        System.out.println("Intentos permitidos: " + MAX_INTENTOS);

        // PI = 4;   // si se descomenta -> ERROR: no se puede reasignar una final

        System.out.println("Mayor int: " + Integer.MAX_VALUE);
        System.out.println("Menor int: " + Integer.MIN_VALUE);
    }
}
