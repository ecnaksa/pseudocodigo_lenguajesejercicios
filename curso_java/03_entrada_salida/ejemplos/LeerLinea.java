/*
 * Leer un numero y luego una linea completa (cuidado con el '\n' pendiente).
 * Prueba: printf "25\nAna Perez\n" | java LeerLinea
 */
import java.util.Scanner;

public class LeerLinea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Edad: ");
        int edad = sc.nextInt();

        sc.nextLine();                 // consume el '\n' que dejo nextInt
        System.out.print("Nombre completo: ");
        String nombre = sc.nextLine(); // ahora si lee la linea con espacios

        System.out.println(nombre + " tiene " + edad + " anios");
        sc.close();
    }
}
