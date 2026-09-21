/* Ejercicio 2 - Maximo de tres enteros. */
import java.util.Scanner;

public class Maximo3 {
    static int maximo3(int a, int b, int c) {
        int mayor = a;
        if (b > mayor) mayor = b;
        if (c > mayor) mayor = c;
        return mayor;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Tres enteros: ");
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        System.out.println("El mayor es " + maximo3(a, b, c));
        sc.close();
    }
}
