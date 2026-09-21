/* Ejercicio 5 (reto) - Piramide de asteriscos con bucles anidados. */
import java.util.Scanner;

public class Piramide {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Altura: ");
        int h = sc.nextInt();

        for (int fila = 1; fila <= h; fila++) {
            for (int col = 1; col <= fila; col++) {
                System.out.print("*");
            }
            System.out.println();
        }
        sc.close();
    }
}
