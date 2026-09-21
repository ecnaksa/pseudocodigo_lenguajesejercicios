/*
 * try/catch basico: manejar ArithmeticException.
 */
public class Dividir {
    static int dividir(int a, int b) {
        return a / b;              // si b es 0, lanza ArithmeticException
    }

    public static void main(String[] args) {
        try {
            System.out.println("10 / 2 = " + dividir(10, 2));   // 5
            System.out.println("10 / 0 = " + dividir(10, 0));   // lanza
            System.out.println("no se imprime");
        } catch (ArithmeticException e) {
            System.out.println("Error atrapado: " + e.getMessage());
        }
        System.out.println("El programa continua normalmente");
    }
}
