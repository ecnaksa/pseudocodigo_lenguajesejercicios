/*
 * Problema 08 - Umbral de Disipacion Termica Media
 * 5 temperaturas: media, cuantas la superan y la lista de esas.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema08 {

    static void umbralMedia(double[] arr, int tam) {
        double suma = 0.0;
        for (int i = 0; i < tam; i++) {
            suma = suma + arr[i];
        }
        double media = suma / tam;
        System.out.printf(Locale.US, "Temperatura media (umbral): %.2f%n", media);

        int cuenta = 0;
        System.out.println("Sensores por encima del umbral:");
        for (int i = 0; i < tam; i++) {
            if (arr[i] > media) {
                cuenta = cuenta + 1;
                System.out.printf(Locale.US, "  sensor %d = %.2f%n", i, arr[i]);
            }
        }
        System.out.println("Cantidad que supera el umbral: " + cuenta);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 5;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Temperatura del sensor " + i + " (C): ");
            arr[i] = sc.nextDouble();
        }
        umbralMedia(arr, tam);
        sc.close();
    }
}
