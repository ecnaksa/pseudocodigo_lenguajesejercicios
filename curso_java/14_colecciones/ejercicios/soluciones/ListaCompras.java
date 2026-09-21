/* Ejercicio 1 - Lista de compras con ArrayList. */
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class ListaCompras {
    public static void main(String[] args) {
        List<String> lista = new ArrayList<>();
        lista.add("Pan");
        lista.add("Leche");
        lista.add("Cafe");
        lista.add("Huevos");

        lista.remove("Cafe");
        Collections.sort(lista);

        System.out.println("Lista final: " + lista);
    }
}
