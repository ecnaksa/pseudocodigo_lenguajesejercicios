/*
 * Problema 27 - Calculo de Derivada Discreta de Senal
 * dv[i] = v[i+1] - v[i]  (el resultado tiene n-1 elementos).
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema27 {

    static void derivada(double[] v, int n, double[] dv) {
        for (int i = 0; i < n - 1; i++) {
            dv[i] = v[i + 1] - v[i];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de voltajes: ");
        int n = sc.nextInt();

        double[] v = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("v[" + i + "]: ");
            v[i] = sc.nextDouble();
        }

        if (n < 2) {
            System.out.println("Se necesitan al menos 2 muestras para la derivada.");
            sc.close();
            return;
        }

        double[] dv = new double[n - 1];
        derivada(v, n, dv);

        System.out.print("Derivada discreta (delta v): ");
        for (int i = 0; i < n - 1; i++) {
            System.out.printf(Locale.US, "%.2f ", dv[i]);
        }
        System.out.println();
        sc.close();
    }
}
