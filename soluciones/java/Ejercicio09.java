/*
 * Ejercicio 09 - Nivel Intermedio
 * Llenar dos vectores A y B de 5 elementos, sumar elemento a elemento
 * (C[i] = A[i] + B[i]) e imprimir el vector C.
 */
import java.util.Scanner;

public class Ejercicio09 {

    static void sumarVectores(int[] A, int[] B, int[] C, int tam) {
        for (int i = 0; i < tam; i++) {
            C[i] = A[i] + B[i];
        }
        System.out.println("Vector C (resultado A + B):");
        for (int i = 0; i < tam; i++) {
            System.out.println("C[" + i + "] = " + C[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 5;
        int[] A = new int[tam];
        int[] B = new int[tam];
        int[] C = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + " de A: ");
            A[i] = sc.nextInt();
            System.out.print("Ingrese el elemento " + i + " de B: ");
            B[i] = sc.nextInt();
        }
        sumarVectores(A, B, C, tam);
        sc.close();
    }
}
