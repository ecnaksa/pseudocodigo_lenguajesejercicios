/*
 * StringBuilder: construir texto eficientemente en un bucle.
 */
public class UsarStringBuilder {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 5; i++) {
            sb.append(i);
            if (i < 5) sb.append(", ");
        }
        System.out.println("Lista: " + sb.toString());   // 1, 2, 3, 4, 5

        StringBuilder palabra = new StringBuilder("Java");
        palabra.reverse();
        System.out.println("Al reves: " + palabra);       // avaJ
    }
}
