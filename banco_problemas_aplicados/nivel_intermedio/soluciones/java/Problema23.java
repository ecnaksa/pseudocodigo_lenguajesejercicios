/*
 * Problema 23 - Inversion Espectral In-Place en Memoria
 * void invertirBuffer(int[] arr, int tam)  -> invierte in-place, solo una variable temporal.
 */
import java.util.Scanner;

public class Problema23 {

    static void invertirBuffer(int[] arr, int tam) {
        for (int i = 0; i < tam / 2; i++) {
            int aux = arr[i];
            arr[i] = arr[tam - 1 - i];
            arr[tam - 1 - i] = aux;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del buffer: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Dato " + i + ": ");
            arr[i] = sc.nextInt();
        }

        invertirBuffer(arr, tam);

        System.out.print("Buffer invertido: ");
        for (int i = 0; i < tam; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
