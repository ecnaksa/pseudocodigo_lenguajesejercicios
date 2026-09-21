/* Ejercicio 3 - Valores unicos con HashSet. */
import java.util.HashSet;
import java.util.Set;

public class Unicos {
    public static void main(String[] args) {
        int[] datos = {5, 2, 8, 2, 5, 1, 8, 8};

        Set<Integer> unicos = new HashSet<>();
        for (int x : datos) {
            unicos.add(x);
        }
        System.out.println("Unicos: " + unicos);   // [1, 2, 5, 8]
    }
}
