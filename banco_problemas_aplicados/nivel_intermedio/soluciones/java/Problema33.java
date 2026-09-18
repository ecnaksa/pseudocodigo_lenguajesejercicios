/*
 * Problema 33 - Compresion de Datos por Submuestreo
 * Toma las muestras en indices 0, K, 2K, ... Devuelve el nuevo tamano.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema33 {

    static int submuestrea(double[] arr, int n, int k, double[] res) {
        int j = 0;
        for (int i = 0; i < n; i = i + k) {
            res[j] = arr[i];
            j = j + 1;
        }
        return j;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Muestra " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        System.out.print("Ingrese el factor de compresion K: ");
        int k = sc.nextInt();

        double[] res = new double[n];
        int nuevo = submuestrea(arr, n, k, res);

        System.out.print("Vector comprimido (" + nuevo + " muestras): ");
        for (int i = 0; i < nuevo; i++) {
            System.out.printf(Locale.US, "%.2f ", res[i]);
        }
        System.out.println();
        sc.close();
    }
}
