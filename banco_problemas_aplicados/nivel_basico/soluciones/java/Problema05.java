/*
 * Problema 05 - Consumo Exclusivo de Cargas Pares
 * double sumaPares(double[] arr, int tam)  -> acumula valores en INDICES pares (i % 2 == 0)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema05 {

    static double sumaPares(double[] arr, int tam) {
        double suma = 0.0;
        for (int i = 0; i < tam; i++) {
            if (i % 2 == 0) {
                suma = suma + arr[i];
            }
        }
        return suma;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de lecturas: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Lectura " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        System.out.printf(Locale.US, "Suma de las cargas en indices pares: %.2f%n", sumaPares(arr, tam));
        sc.close();
    }
}
