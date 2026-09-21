/*
 * switch de expresion (Java 14+): devuelve un valor, usa ->, sin break.
 * Prueba: printf "3\n" | java SwitchExpresion
 */
import java.util.Scanner;

public class SwitchExpresion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Dia (1-7): ");
        int dia = sc.nextInt();

        String nombre = switch (dia) {
            case 1 -> "Lunes";
            case 2 -> "Martes";
            case 3 -> "Miercoles";
            case 4 -> "Jueves";
            case 5 -> "Viernes";
            case 6, 7 -> "Fin de semana";     // varios casos juntos
            default -> "Dia invalido";
        };
        System.out.println(nombre);
        sc.close();
    }
}
