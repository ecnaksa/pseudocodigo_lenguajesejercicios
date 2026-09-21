/*
 * Varios catch y finally (que se ejecuta siempre).
 */
public class ConFinally {
    public static void main(String[] args) {
        int[] a = {1, 2, 3};

        try {
            System.out.println(a[5]);      // ArrayIndexOutOfBoundsException
        } catch (ArithmeticException e) {
            System.out.println("Aritmetico: " + e.getMessage());
        } catch (Exception e) {            // atrapa el resto
            System.out.println("Error: " + e.getClass().getSimpleName());
        } finally {
            System.out.println("Bloque finally: siempre se ejecuta");
        }
    }
}
