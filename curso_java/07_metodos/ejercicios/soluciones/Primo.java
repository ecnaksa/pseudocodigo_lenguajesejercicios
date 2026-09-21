/* Ejercicio 3 - esPrimo y lista de primos hasta 30. */
public class Primo {
    static boolean esPrimo(int n) {
        if (n < 2) return false;
        for (int d = 2; d * d <= n; d++) {     // basta hasta la raiz
            if (n % d == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.print("Primos hasta 30: ");
        for (int i = 2; i <= 30; i++) {
            if (esPrimo(i)) System.out.print(i + " ");
        }
        System.out.println();
    }
}
