/*
 * Problema 10 - Multiplicacion Cruzada Inversa en Retardos
 * C[i] = A[i] * B[tam-1-i]  (vectores de 10)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema10 {

    static void multCruzada(int tam, double[] A, double[] B, double[] C) {
        for (int i = 0; i < tam; i++) {
            C[i] = A[i] * B[tam - 1 - i];
        }
        System.out.println("Vector resultante C (cruce A * B):");
        for (int i = 0; i < tam; i++) {
            System.out.printf(Locale.US, "C[%d] = %.2f%n", i, C[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 10;
        double[] A = new double[tam];
        double[] B = new double[tam];
        double[] C = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("A[" + i + "]: ");
            A[i] = sc.nextDouble();
            System.out.print("B[" + i + "]: ");
            B[i] = sc.nextDouble();
        }
        multCruzada(tam, A, B, C);
        sc.close();
    }
}
