/*
 * for-each: recorrer un arreglo sin manejar indices.
 */
public class ForEach {
    public static void main(String[] args) {
        int[] numeros = {10, 20, 30, 40, 50};

        System.out.print("Elementos: ");
        for (int n : numeros) {
            System.out.print(n + " ");
        }
        System.out.println();

        int suma = 0;
        for (int n : numeros) suma += n;
        System.out.println("Suma: " + suma);   // 150
    }
}
