/*
 * La clase de utilidad java.util.Arrays.
 */
import java.util.Arrays;

public class UtilArrays {
    public static void main(String[] args) {
        int[] a = {5, 2, 8, 1, 9};

        System.out.println("Original: " + Arrays.toString(a));

        Arrays.sort(a);
        System.out.println("Ordenado: " + Arrays.toString(a));

        int[] copia = Arrays.copyOf(a, a.length);
        Arrays.fill(copia, 0);
        System.out.println("Copia rellenada: " + Arrays.toString(copia));
    }
}
