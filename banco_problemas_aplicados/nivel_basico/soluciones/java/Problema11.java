/*
 * Problema 11 - Deteccion de Pico Maximo Absoluto
 * 15 muestras (valores unicos): imprimir el valor maximo y su posicion.
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema11 {

    static void picoMaximo(double[] arr, int tam) {
        double mayor = arr[0];
        int posicion = 0;
        for (int i = 1; i < tam; i++) {
            if (arr[i] > mayor) {
                mayor = arr[i];
                posicion = i;
            }
        }
        System.out.printf(Locale.US, "Pico maximo: %.2f%n", mayor);
        System.out.println("Posicion (indice) del pico: " + posicion);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 15;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Muestra " + i + " (V): ");
            arr[i] = sc.nextDouble();
        }
        picoMaximo(arr, tam);
        sc.close();
    }
}
