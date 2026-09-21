/* Ejercicio 5 (reto) - Potencia recursiva. */
import java.util.Scanner;

public class Potencia {
    static long potencia(int base, int exp) {
        if (exp == 0) return 1;                 // caso base
        return base * potencia(base, exp - 1);  // caso recursivo
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Base y exponente: ");
        int base = sc.nextInt(), exp = sc.nextInt();
        System.out.println(base + "^" + exp + " = " + potencia(base, exp));
        sc.close();
    }
}
