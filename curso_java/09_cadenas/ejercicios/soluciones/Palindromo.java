/* Ejercicio 2 - Palindromo. */
import java.util.Scanner;

public class Palindromo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Palabra: ");
        String s = sc.next();

        boolean esPalindromo = true;
        int largo = s.length();
        for (int i = 0; i < largo / 2; i++) {
            if (s.charAt(i) != s.charAt(largo - 1 - i)) {
                esPalindromo = false;
                break;
            }
        }
        System.out.println(esPalindromo ? "Es palindromo" : "No es palindromo");
        sc.close();
    }
}
