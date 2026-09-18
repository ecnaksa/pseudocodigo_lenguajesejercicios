/*
 * Problema 14 - Ordenamiento Lineal Simple por Intercambio (burbuja)
 * 8 valores de calibracion, orden ascendente.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema14 {

    static void ordenaIntercambio(double[] arr, int tam) {
        for (int i = 0; i < tam; i++) {
            for (int f = 0; f < tam - 1 - i; f++) {
                if (arr[f] > arr[f + 1]) {
                    double aux = arr[f];
                    arr[f] = arr[f + 1];
                    arr[f + 1] = aux;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 8;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Valor de calibracion " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        ordenaIntercambio(arr, tam);

        System.out.print("Valores ordenados: ");
        for (int i = 0; i < tam; i++) {
            System.out.printf(Locale.US, "%.2f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
