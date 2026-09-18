/*
 * Problema 01 - Suma de Muestras de Corriente ADC
 * double sumaCorrientes(double[] arr, int tam)  -> sumatoria total (amperios)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema01 {

    static double sumaCorrientes(double[] arr, int tam) {
        double suma = 0.0;
        for (int i = 0; i < tam; i++) {
            suma = suma + arr[i];
        }
        return suma;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Muestra " + i + " (A): ");
            arr[i] = sc.nextDouble();
        }

        System.out.printf(Locale.US, "Suma total de corrientes: %.2f A%n", sumaCorrientes(arr, tam));
        sc.close();
    }
}
