/* Ejercicio 3 - Iniciales de cada palabra de un nombre. */
import java.util.Scanner;

public class Iniciales {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nombre completo: ");
        String nombre = sc.nextLine();

        String[] palabras = nombre.split(" ");
        System.out.print("Iniciales: ");
        for (String p : palabras) {
            if (!p.isEmpty()) {
                System.out.print(p.charAt(0) + ".");
            }
        }
        System.out.println();
        sc.close();
    }
}
