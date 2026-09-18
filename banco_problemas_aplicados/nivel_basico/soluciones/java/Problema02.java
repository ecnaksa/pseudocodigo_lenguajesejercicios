/*
 * Problema 02 - Voltaje Minimo en Banco Solar
 * double buscaMinimo(double[] arr, int tam)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema02 {

    static double buscaMinimo(double[] arr, int tam) {
        double min = arr[0];
        for (int i = 1; i < tam; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de celdas: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Voltaje de la celda " + i + " (V): ");
            arr[i] = sc.nextDouble();
        }

        System.out.printf(Locale.US, "Voltaje minimo detectado: %.2f V%n", buscaMinimo(arr, tam));
        sc.close();
    }
}
