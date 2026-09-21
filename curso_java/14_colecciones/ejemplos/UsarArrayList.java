/*
 * ArrayList: lista dinamica. Agregar, acceder, recorrer, modificar.
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class UsarArrayList {
    public static void main(String[] args) {
        List<String> nombres = new ArrayList<>();   // declarar con la interfaz List
        nombres.add("Ana");
        nombres.add("Luis");
        nombres.add("Sara");

        System.out.println("Tamano: " + nombres.size());
        System.out.println("Primero: " + nombres.get(0));

        nombres.set(1, "Luisa");            // reemplazar
        nombres.remove("Sara");             // quitar

        Collections.sort(nombres);          // ordenar
        System.out.println("Ordenada: " + nombres);

        for (String n : nombres) {
            System.out.println(" - " + n);
        }
    }
}
