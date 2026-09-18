/*
 * Problema 36 - Concatenacion Segura de Dos Buffers
 * Une A y B en C (de tamano nA + nB), copiando secuencialmente.
 */
import java.util.Scanner;

public class Problema36 {

    static void concatena(int[] A, int nA, int[] B, int nB, int[] C) {
        int k = 0;
        for (int i = 0; i < nA; i++) {
            C[k] = A[i];
            k = k + 1;
        }
        for (int i = 0; i < nB; i++) {
            C[k] = B[i];
            k = k + 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Tamano del Vector 1: ");
        int nA = sc.nextInt();
        int[] A = new int[nA];
        for (int i = 0; i < nA; i++) {
            System.out.print("A[" + i + "]: ");
            A[i] = sc.nextInt();
        }

        System.out.print("Tamano del Vector 2: ");
        int nB = sc.nextInt();
        int[] B = new int[nB];
        for (int i = 0; i < nB; i++) {
            System.out.print("B[" + i + "]: ");
            B[i] = sc.nextInt();
        }

        int[] C = new int[nA + nB];
        concatena(A, nA, B, nB, C);

        System.out.print("Vector combinado (" + (nA + nB) + " elementos): ");
        for (int i = 0; i < nA + nB; i++) {
            System.out.print(C[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
