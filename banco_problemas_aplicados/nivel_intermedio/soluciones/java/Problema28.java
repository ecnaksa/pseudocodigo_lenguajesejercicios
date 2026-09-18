/*
 * Problema 28 - Normalizacion Lineal de Rango [0.0, 1.0]
 * Divide cada valor entre el maximo absoluto hallado.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema28 {

    static void normaliza(double[] arr, int n) {
        double maxVal = Math.abs(arr[0]);
        for (int i = 1; i < n; i++) {
            if (Math.abs(arr[i]) > maxVal) {
                maxVal = Math.abs(arr[i]);
            }
        }
        if (maxVal == 0.0) {
            return;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / maxVal;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de valores: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Valor " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        normaliza(arr, n);

        System.out.print("Vector normalizado: ");
        for (int i = 0; i < n; i++) {
            System.out.printf(Locale.US, "%.3f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
