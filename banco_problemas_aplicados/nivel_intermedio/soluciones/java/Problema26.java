/*
 * Problema 26 - Desplazamiento Circular de Muestras
 * void rotaDerecha(double[] arr, int tam, int k)  -> rota a la derecha K posiciones (ciclico).
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema26 {

    static void rotaDerecha(double[] arr, int tam, int k) {
        k = k % tam;
        double[] aux = new double[tam];
        for (int i = 0; i < tam; i++) {
            aux[(i + k) % tam] = arr[i];
        }
        for (int i = 0; i < tam; i++) {
            arr[i] = aux[i];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Muestra " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        System.out.print("Ingrese K (posiciones a rotar a la derecha): ");
        int k = sc.nextInt();

        rotaDerecha(arr, tam, k);

        System.out.print("Buffer desplazado: ");
        for (int i = 0; i < tam; i++) {
            System.out.printf(Locale.US, "%.2f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
