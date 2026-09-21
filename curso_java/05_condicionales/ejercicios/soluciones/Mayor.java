/* Ejercicio 1 - Mayor de dos numeros. */
import java.util.Scanner;

public class Mayor {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("a: ");
        int a = sc.nextInt();
        System.out.print("b: ");
        int b = sc.nextInt();

        int mayor = (a > b) ? a : b;
        System.out.println("El mayor es " + mayor);
        sc.close();
    }
}
