/*
 * Problema 17 - Desplazamiento Lineal de Buffer FIFO
 * void desplazaFIFO(double[] arr, int tam, double nueva)
 * Mueve todo una posicion a la derecha (recorriendo DESDE EL FINAL) e inserta 'nueva' en arr[0].
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema17 {

    static void desplazaFIFO(double[] arr, int tam, double nueva) {
        for (int i = tam - 1; i >= 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = nueva;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del buffer: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Registro " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        System.out.print("Nueva lectura a insertar: ");
        double nueva = sc.nextDouble();

        desplazaFIFO(arr, tam, nueva);

        System.out.print("Buffer tras el desplazamiento: ");
        for (int i = 0; i < tam; i++) {
            System.out.printf(Locale.US, "%.2f ", arr[i]);
        }
        System.out.println();
        sc.close();
    }
}
