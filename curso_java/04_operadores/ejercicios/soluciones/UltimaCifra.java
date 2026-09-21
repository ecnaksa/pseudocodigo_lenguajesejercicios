/* Ejercicio 5 (reto) - Ultima cifra y numero sin ella. */
import java.util.Scanner;

public class UltimaCifra {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero: ");
        int n = sc.nextInt();

        System.out.println("Ultima cifra: " + (n % 10));
        System.out.println("Sin la ultima cifra: " + (n / 10));
        sc.close();
    }
}
