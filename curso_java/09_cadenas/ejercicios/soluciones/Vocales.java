/* Ejercicio 1 - Contar vocales de una palabra. */
import java.util.Scanner;

public class Vocales {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Palabra: ");
        String palabra = sc.next().toLowerCase();

        int vocales = 0;
        for (int i = 0; i < palabra.length(); i++) {
            char c = palabra.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            }
        }
        System.out.println("Vocales: " + vocales);
        sc.close();
    }
}
