/*
 * Lambdas: ordenar con Comparator, forEach con referencia a metodo.
 */
import java.util.ArrayList;
import java.util.List;

public class Lambdas {
    public static void main(String[] args) {
        List<String> nombres = new ArrayList<>(List.of("Carlos", "Ana", "Beto"));

        // Ordenar por longitud con una lambda
        nombres.sort((a, b) -> a.length() - b.length());
        System.out.println("Por longitud: " + nombres);

        // Ordenar alfabeticamente
        nombres.sort((a, b) -> a.compareTo(b));
        System.out.println("Alfabetico: " + nombres);

        // forEach con referencia a metodo
        System.out.println("Uno por uno:");
        nombres.forEach(System.out::println);
    }
}
