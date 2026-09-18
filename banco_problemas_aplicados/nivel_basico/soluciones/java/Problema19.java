/*
 * Problema 19 - Inversion Espejo de Primera Mitad
 * void espejoPrimeraMitad(double[] arr, int n)  ->  arr[n-1-i] = arr[i]  (queda simetrico)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema19 {

    static void espejoPrimeraMitad(double[] arr, int n) {
        for (int i = 0; i < n / 2; i++) {
            arr[n - 1 - i] = arr[i];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del vector: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Dato " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        espejoPrimeraMitad(arr, n);

        System.out.print("Vector simetrizado: ");
        for (int i = 0; i < n; i++) {
            System.out.printf(Locale.US, "%.2f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
