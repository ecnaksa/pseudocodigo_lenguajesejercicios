/* Ejercicio 1 - Raiz cuadrada segura con excepcion. */
public class RaizSegura {
    static double raiz(double x) {
        if (x < 0) throw new IllegalArgumentException("no existe raiz real de un negativo");
        return Math.sqrt(x);
    }

    public static void main(String[] args) {
        double[] valores = {16, -4, 2};
        for (double v : valores) {
            try {
                System.out.println("raiz(" + v + ") = " + raiz(v));
            } catch (IllegalArgumentException e) {
                System.out.println("Error con " + v + ": " + e.getMessage());
            }
        }
    }
}
