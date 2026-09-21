/* Ejercicio 2 - Mostrar un arreglo al reves. */
import java.util.Scanner;

public class Invertir {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[5];
        System.out.println("Cinco enteros:");
        for (int i = 0; i < a.length; i++) a[i] = sc.nextInt();

        System.out.print("Al reves: ");
        for (int i = a.length - 1; i >= 0; i--) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
