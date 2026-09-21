/* Ejercicio 4 - Menu con switch de expresion. */
import java.util.Scanner;

public class Menu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Opcion (1-3): ");
        int op = sc.nextInt();

        String accion = switch (op) {
            case 1 -> "Iniciar partida";
            case 2 -> "Cargar partida";
            case 3 -> "Salir";
            default -> "Opcion invalida";
        };
        System.out.println(accion);
        sc.close();
    }
}
