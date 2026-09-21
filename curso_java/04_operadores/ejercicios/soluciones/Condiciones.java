/* Ejercicio 4 - Evaluar condiciones (resultado boolean). */
import java.util.Scanner;

public class Condiciones {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Edad: ");
        int edad = sc.nextInt();

        System.out.println("edad >= 18            -> " + (edad >= 18));
        System.out.println("18 <= edad <= 65      -> " + (edad >= 18 && edad <= 65));
        System.out.println("edad < 12 O edad > 65 -> " + (edad < 12 || edad > 65));
        sc.close();
    }
}
