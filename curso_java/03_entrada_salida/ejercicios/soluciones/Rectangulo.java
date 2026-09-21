/* Ejercicio 4 - Area y perimetro de un rectangulo. */
import java.util.Scanner;

public class Rectangulo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Base: ");
        int base = sc.nextInt();
        System.out.print("Altura: ");
        int altura = sc.nextInt();

        System.out.println("Area: " + (base * altura));
        System.out.println("Perimetro: " + (2 * (base + altura)));
        sc.close();
    }
}
