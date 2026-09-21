/* Ejercicio 4 (reto) - Promedio con streams (mapToInt + average). */
import java.util.List;

public class PromedioStream {
    public static void main(String[] args) {
        List<Integer> valores = List.of(10, 20, 30, 40, 50);

        double promedio = valores.stream()
                .mapToInt(Integer::intValue)
                .average()
                .orElse(0);          // average devuelve un OptionalDouble

        System.out.println("Promedio: " + promedio);   // 30.0
    }
}
