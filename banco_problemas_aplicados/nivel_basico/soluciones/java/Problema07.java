/*
 * Problema 07 - Clasificador de Polaridad AC
 * 10 lecturas: contar ceros/positivos/negativos y sumar positivos y negativos.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema07 {

    static void clasificaPolaridad(double[] arr, int tam) {
        int ceros = 0, pos = 0, neg = 0;
        double spos = 0.0, sneg = 0.0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] == 0.0) {
                ceros = ceros + 1;
            } else if (arr[i] > 0.0) {
                pos = pos + 1;
                spos = spos + arr[i];
            } else {
                neg = neg + 1;
                sneg = sneg + arr[i];
            }
        }
        System.out.println("Ceros exactos: " + ceros);
        System.out.printf(Locale.US, "Positivos: %d  (suma = %.2f)%n", pos, spos);
        System.out.printf(Locale.US, "Negativos: %d  (suma = %.2f)%n", neg, sneg);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 10;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Lectura de tension " + i + " (V): ");
            arr[i] = sc.nextDouble();
        }
        clasificaPolaridad(arr, tam);
        sc.close();
    }
}
