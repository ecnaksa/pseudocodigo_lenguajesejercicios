/*
 * Problema 37 - Calculo del Producto Punto de Vectores
 * double productoPunto(double[] A, double[] B, int n)  -> escalar = suma de A[i]*B[i].
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema37 {

    static double productoPunto(double[] A, double[] B, int n) {
        double suma = 0.0;
        for (int i = 0; i < n; i++) {
            suma = suma + A[i] * B[i];
        }
        return suma;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano de los vectores: ");
        int n = sc.nextInt();

        double[] A = new double[n];
        double[] B = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("A[" + i + "]: ");
            A[i] = sc.nextDouble();
            System.out.print("B[" + i + "]: ");
            B[i] = sc.nextDouble();
        }

        System.out.printf(Locale.US, "Producto punto A . B = %.2f%n", productoPunto(A, B, n));
        sc.close();
    }
}
