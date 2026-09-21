/* Ejercicio 3 - Pasar nombres a mayusculas con map. */
import java.util.List;
import java.util.stream.Collectors;

public class Mayusculas {
    public static void main(String[] args) {
        List<String> nombres = List.of("ana", "luis", "sara");

        List<String> enMayusculas = nombres.stream()
                .map(String::toUpperCase)
                .collect(Collectors.toList());

        System.out.println(enMayusculas);   // [ANA, LUIS, SARA]
    }
}
