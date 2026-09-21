/*
 * HashSet: elementos unicos. Ideal para quitar duplicados.
 */
import java.util.HashSet;
import java.util.Set;
import java.util.List;

public class UsarHashSet {
    public static void main(String[] args) {
        List<Integer> datos = List.of(3, 1, 4, 1, 5, 9, 2, 6, 5, 3);

        Set<Integer> unicos = new HashSet<>(datos);   // el set descarta duplicados

        System.out.println("Originales: " + datos.size());
        System.out.println("Unicos: " + unicos.size() + " -> " + unicos);
        System.out.println("Contiene el 4? " + unicos.contains(4));
    }
}
