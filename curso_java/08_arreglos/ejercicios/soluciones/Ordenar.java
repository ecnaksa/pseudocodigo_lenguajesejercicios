/* Ejercicio 4 - Ordenar con Arrays.sort. */
import java.util.Arrays;

public class Ordenar {
    public static void main(String[] args) {
        int[] a = {42, 7, 19, 3, 88, 25};
        System.out.println("Antes:   " + Arrays.toString(a));
        Arrays.sort(a);
        System.out.println("Despues: " + Arrays.toString(a));
    }
}
