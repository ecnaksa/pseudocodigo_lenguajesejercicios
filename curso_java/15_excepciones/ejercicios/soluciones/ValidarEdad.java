/* Ejercicio 2 - Validar edad con excepcion. */
public class ValidarEdad {
    static void validar(int e) {
        if (e < 0)   throw new IllegalArgumentException("edad negativa");
        if (e > 150) throw new IllegalArgumentException("edad demasiado grande");
        System.out.println("Edad valida: " + e);
    }

    public static void main(String[] args) {
        int[] edades = {25, -3, 200};
        for (int e : edades) {
            try {
                validar(e);
            } catch (IllegalArgumentException ex) {
                System.out.println("Error con " + e + ": " + ex.getMessage());
            }
        }
    }
}
