/*
 * HashMap: diccionario clave -> valor. Aqui contamos letras con getOrDefault.
 */
import java.util.HashMap;
import java.util.Map;

public class UsarHashMap {
    public static void main(String[] args) {
        Map<String, Integer> edades = new HashMap<>();
        edades.put("Ana", 25);
        edades.put("Luis", 30);

        System.out.println("Edad de Ana: " + edades.get("Ana"));
        for (var e : edades.entrySet()) {
            System.out.println("  " + e.getKey() + " = " + e.getValue());
        }

        // contar frecuencia de letras con getOrDefault
        String texto = "banana";
        Map<Character, Integer> frec = new HashMap<>();
        for (char c : texto.toCharArray()) {
            frec.put(c, frec.getOrDefault(c, 0) + 1);
        }
        System.out.println("Frecuencia: " + frec);   // {a=3, b=1, n=2}
    }
}
