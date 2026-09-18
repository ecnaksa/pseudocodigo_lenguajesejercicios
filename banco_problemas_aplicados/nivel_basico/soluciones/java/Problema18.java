/*
 * Problema 18 - Comparacion de Dos Canales de Telemetria
 * boolean sonIguales(int[] A, int[] B, int tam)  -> true si A y B son identicos elemento por elemento
 */
import java.util.Scanner;

public class Problema18 {

    static boolean sonIguales(int[] A, int[] B, int tam) {
        for (int i = 0; i < tam; i++) {
            if (A[i] != B[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano de los canales: ");
        int tam = sc.nextInt();

        int[] A = new int[tam];
        int[] B = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Canal A, dato " + i + ": ");
            A[i] = sc.nextInt();
            System.out.print("Canal B, dato " + i + ": ");
            B[i] = sc.nextInt();
        }

        if (sonIguales(A, B, tam)) {
            System.out.println("Los dos canales son identicos.");
        } else {
            System.out.println("Los canales difieren.");
        }
        sc.close();
    }
}
