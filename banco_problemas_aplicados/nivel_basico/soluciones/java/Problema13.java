/*
 * Problema 13 - Calculo de Potencia Aparente Promedio
 * double potenciaPromedio(double[] V, double[] I, int n)  -> (suma de V[i]*I[i]) / n
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema13 {

    static double potenciaPromedio(double[] V, double[] I, int n) {
        double suma = 0.0;
        for (int i = 0; i < n; i++) {
            suma = suma + V[i] * I[i];
        }
        return suma / n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int n = sc.nextInt();

        double[] V = new double[n];
        double[] I = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("V[" + i + "] (V): ");
            V[i] = sc.nextDouble();
            System.out.print("I[" + i + "] (A): ");
            I[i] = sc.nextDouble();
        }

        System.out.printf(Locale.US, "Potencia aparente promedio: %.2f%n", potenciaPromedio(V, I, n));
        sc.close();
    }
}
