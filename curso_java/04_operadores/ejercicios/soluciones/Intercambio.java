/* Ejercicio 3 - Intercambiar dos variables con una temporal. */
import java.util.Scanner;

public class Intercambio {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("a: ");
        int a = sc.nextInt();
        System.out.print("b: ");
        int b = sc.nextInt();

        System.out.println("Antes:   a=" + a + ", b=" + b);
        int temp = a;
        a = b;
        b = temp;
        System.out.println("Despues: a=" + a + ", b=" + b);
        sc.close();
    }
}
