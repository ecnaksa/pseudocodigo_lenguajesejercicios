/*
 * else if encadenado: nota numerica a letra.
 */
import java.util.Scanner;

public class Calificacion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nota (0-100): ");
        int nota = sc.nextInt();

        if (nota >= 90) {
            System.out.println("A - Excelente");
        } else if (nota >= 80) {
            System.out.println("B - Muy bien");
        } else if (nota >= 70) {
            System.out.println("C - Aprobado");
        } else if (nota >= 60) {
            System.out.println("D - Justo");
        } else {
            System.out.println("F - Reprobado");
        }
        sc.close();
    }
}
