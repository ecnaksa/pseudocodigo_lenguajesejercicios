/*
 * Problema 25 - Particion Pares/Impares en Vector
 * Primero los valores de indices pares, luego los de indices impares, en un arreglo auxiliar.
 */
import java.util.Scanner;

public class Problema25 {

    static void particiona(int[] arr, int tam, int[] res) {
        int k = 0;
        for (int i = 0; i < tam; i++) {
            if (i % 2 == 0) {
                res[k] = arr[i];
                k = k + 1;
            }
        }
        for (int i = 0; i < tam; i++) {
            if (i % 2 != 0) {
                res[k] = arr[i];
                k = k + 1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del vector: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        int[] res = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Dato " + i + ": ");
            arr[i] = sc.nextInt();
        }

        particiona(arr, tam, res);

        System.out.print("Vector particionado (pares | impares): ");
        for (int i = 0; i < tam; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
