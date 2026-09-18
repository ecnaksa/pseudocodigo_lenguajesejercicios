/*
 * Problema 09 - Superposicion Lineal de Dos Canales (A + B)
 * C[i] = A[i] + B[i]  (vectores de 5)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema09 {

    static void superpone(double[] A, double[] B, double[] C, int tam) {
        for (int i = 0; i < tam; i++) {
            C[i] = A[i] + B[i];
        }
        System.out.println("Vector resultante C (A + B):");
        for (int i = 0; i < tam; i++) {
            System.out.printf(Locale.US, "C[%d] = %.2f%n", i, C[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 5;
        double[] A = new double[tam];
        double[] B = new double[tam];
        double[] C = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Canal A, muestra " + i + ": ");
            A[i] = sc.nextDouble();
            System.out.print("Canal B, muestra " + i + ": ");
            B[i] = sc.nextDouble();
        }
        superpone(A, B, C, tam);
        sc.close();
    }
}
