/* Ejercicio 5 (reto) - Leer edad y luego el nombre completo (con nextLine extra). */
import java.util.Scanner;

public class SaludoNombre {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Edad: ");
        int edad = sc.nextInt();

        sc.nextLine();                 // consume el '\n' pendiente
        System.out.print("Nombre completo: ");
        String nombre = sc.nextLine();

        System.out.println("Hola " + nombre + ", tienes " + edad + " anios");
        sc.close();
    }
}
