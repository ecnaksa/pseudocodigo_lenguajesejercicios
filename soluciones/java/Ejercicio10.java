/*
 * Ejercicio 10 - Nivel Intermedio
 * Multiplicar A y B "cruzados": C[i] = A[i] * B[tam-1-i], guardando de izq. a der.
 */
import java.util.Scanner;

public class Ejercicio10 {

    static void multiplicarVectores(int tam, int[] A, int[] B, int[] C) {
        for (int i = 0; i < tam; i++) {
            C[i] = A[i] * B[tam - 1 - i];
        }
        System.out.println("Vector C (resultado del cruce A * B):");
        for (int i = 0; i < tam; i++) {
            System.out.println("C[" + i + "] = " + C[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 10;
        int[] A = new int[tam];
        int[] B = new int[tam];
        int[] C = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + " de A: ");
            A[i] = sc.nextInt();
            System.out.print("Ingrese el elemento " + i + " de B: ");
            B[i] = sc.nextInt();
        }
        multiplicarVectores(tam, A, B, C);
        sc.close();
    }
}
