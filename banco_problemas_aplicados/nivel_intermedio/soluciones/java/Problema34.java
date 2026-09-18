/*
 * Problema 34 - Verificacion de Orden Estricto Creciente
 * boolean esCreciente(double[] arr, int tam)  ->  arr[i] < arr[i+1] para todo i.
 */
import java.util.Scanner;

public class Problema34 {

    static boolean esCreciente(double[] arr, int tam) {
        for (int i = 0; i < tam - 1; i++) {
            if (!(arr[i] < arr[i + 1])) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del vector: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Calibracion " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        if (esCreciente(arr, tam)) {
            System.out.println("El vector esta estrictamente ordenado de forma ascendente.");
        } else {
            System.out.println("El vector NO esta estrictamente ordenado.");
        }
        sc.close();
    }
}
