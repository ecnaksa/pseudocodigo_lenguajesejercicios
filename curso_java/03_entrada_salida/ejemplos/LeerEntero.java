/*
 * Leer un entero con Scanner.
 * Prueba: printf "25\n" | java LeerEntero
 */
import java.util.Scanner;

public class LeerEntero {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Tu edad: ");
        int edad = sc.nextInt();

        System.out.println("El proximo anio tendras " + (edad + 1));
        sc.close();
    }
}
