/* Ejercicio 2 - Frecuencia de palabras con HashMap. */
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Frecuencia {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Frase: ");
        String frase = sc.nextLine();

        Map<String, Integer> conteo = new HashMap<>();
        for (String palabra : frase.split(" ")) {
            if (!palabra.isEmpty()) {
                conteo.put(palabra, conteo.getOrDefault(palabra, 0) + 1);
            }
        }
        for (var e : conteo.entrySet()) {
            System.out.println(e.getKey() + ": " + e.getValue());
        }
        sc.close();
    }
}
