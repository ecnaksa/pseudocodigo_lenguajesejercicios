/*
 * Streams: filter, map, collect, count, sum.
 */
import java.util.List;
import java.util.stream.Collectors;

public class Streams {
    public static void main(String[] args) {
        List<Integer> numeros = List.of(5, 2, 8, 1, 9, 4, 2);

        // Suma de los pares
        int sumaPares = numeros.stream()
                .filter(n -> n % 2 == 0)
                .mapToInt(Integer::intValue)
                .sum();
        System.out.println("Suma de pares: " + sumaPares);   // 16

        // Cuantos mayores que 4
        long grandes = numeros.stream().filter(n -> n > 4).count();
        System.out.println("Mayores que 4: " + grandes);      // 2

        // Nombres largos, sin duplicados, en una lista
        List<String> nombres = List.of("Ana", "Beto", "Carlos", "Ana");
        List<String> largos = nombres.stream()
                .filter(n -> n.length() > 3)
                .distinct()
                .collect(Collectors.toList());
        System.out.println("Largos: " + largos);              // [Beto, Carlos]

        // Longitudes con map
        List<Integer> longitudes = nombres.stream()
                .map(String::length)
                .collect(Collectors.toList());
        System.out.println("Longitudes: " + longitudes);      // [3, 4, 6, 3]
    }
}
