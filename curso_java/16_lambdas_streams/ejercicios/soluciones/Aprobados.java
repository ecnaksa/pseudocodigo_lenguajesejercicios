/* Ejercicio 2 - Contar aprobados (>= 60) con filter + count. */
import java.util.List;

public class Aprobados {
    public static void main(String[] args) {
        List<Integer> notas = List.of(45, 70, 88, 55, 60, 92, 30);

        long aprobados = notas.stream()
                .filter(n -> n >= 60)
                .count();

        System.out.println("Aprobados: " + aprobados + " de " + notas.size());   // 4 de 7
    }
}
