/*
 * Problema 35 - Remocion de Valores Anomalos (Outliers)
 * Reemplaza por la media local (vecinos) las lecturas que excedan 2 desviaciones estandar.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema35 {

    static void removeOutliers(double[] arr, int n, double[] res) {
        double suma = 0.0;
        for (int i = 0; i < n; i++) {
            suma = suma + arr[i];
        }
        double media = suma / n;

        double sumaCuad = 0.0;
        for (int i = 0; i < n; i++) {
            sumaCuad = sumaCuad + (arr[i] - media) * (arr[i] - media);
        }
        double desv = Math.sqrt(sumaCuad / n);

        for (int i = 0; i < n; i++) {
            if (Math.abs(arr[i] - media) > 2.0 * desv) {
                if (i == 0) {
                    res[i] = arr[i + 1];
                } else if (i == n - 1) {
                    res[i] = arr[i - 1];
                } else {
                    res[i] = (arr[i - 1] + arr[i + 1]) / 2.0;
                }
            } else {
                res[i] = arr[i];
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de lecturas: ");
        int n = sc.nextInt();

        double[] arr = new double[n];
        double[] res = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Lectura " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        removeOutliers(arr, n, res);

        System.out.print("Vector depurado: ");
        for (int i = 0; i < n; i++) {
            System.out.printf(Locale.US, "%.2f ", res[i]);
        }
        System.out.println();
        sc.close();
    }
}
