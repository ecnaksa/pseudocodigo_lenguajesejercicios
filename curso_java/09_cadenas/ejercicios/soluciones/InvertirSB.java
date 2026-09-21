/* Ejercicio 4 (reto) - Invertir una frase con StringBuilder. */
import java.util.Scanner;

public class InvertirSB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Frase: ");
        String frase = sc.nextLine();

        String invertida = new StringBuilder(frase).reverse().toString();
        System.out.println("Al reves: " + invertida);
        sc.close();
    }
}
