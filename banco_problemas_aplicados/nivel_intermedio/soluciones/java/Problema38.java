/*
 * Problema 38 - Inversion Condicional de Negativos
 * Rectifica: aplica valor absoluto solo donde arr[i] < 0.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema38 {

    static void rectifica(double[] arr, int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                arr[i] = -arr[i];
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de mediciones: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Medicion " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        rectifica(arr, n);

        System.out.print("Senal rectificada: ");
        for (int i = 0; i < n; i++) {
            System.out.printf(Locale.US, "%.2f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
