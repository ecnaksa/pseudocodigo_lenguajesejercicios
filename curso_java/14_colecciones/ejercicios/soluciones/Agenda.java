/* Ejercicio 4 (reto) - Agenda con HashMap. */
import java.util.HashMap;
import java.util.Map;

public class Agenda {
    public static void main(String[] args) {
        Map<String, String> agenda = new HashMap<>();
        agenda.put("Ana", "555-1234");
        agenda.put("Luis", "555-5678");
        agenda.put("Sara", "555-9012");

        System.out.println("Contactos:");
        for (var e : agenda.entrySet()) {
            System.out.println("  " + e.getKey() + ": " + e.getValue());
        }

        String quien = "Luis";
        if (agenda.containsKey(quien)) {
            System.out.println("Telefono de " + quien + ": " + agenda.get(quien));
        }
    }
}
