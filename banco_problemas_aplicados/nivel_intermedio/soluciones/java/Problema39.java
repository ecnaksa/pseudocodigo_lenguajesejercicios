/*
 * Problema 39 - Analisis de Simetria Espectral Basica
 * boolean esSimetrico(double[] arr, int n)  ->  arr[i] == arr[n-1-i] (palindromo).
 */
import java.util.Scanner;

public class Problema39 {

    static boolean esSimetrico(double[] arr, int n) {
        for (int i = 0; i < n / 2; i++) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del vector: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Elemento " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        if (esSimetrico(arr, n)) {
            System.out.println("El vector es simetrico (mitades opuestas coinciden).");
        } else {
            System.out.println("El vector NO es simetrico.");
        }
        sc.close();
    }
}
