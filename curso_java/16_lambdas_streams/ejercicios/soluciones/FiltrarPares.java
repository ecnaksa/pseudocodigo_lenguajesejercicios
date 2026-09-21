/* Ejercicio 1 - Filtrar pares con stream. */
import java.util.List;
import java.util.stream.Collectors;

public class FiltrarPares {
    public static void main(String[] args) {
        List<Integer> numeros = List.of(1, 2, 3, 4, 5, 6, 7, 8);

        List<Integer> pares = numeros.stream()
                .filter(n -> n % 2 == 0)
                .collect(Collectors.toList());

        System.out.println("Pares: " + pares);   // [2, 4, 6, 8]
    }
}
