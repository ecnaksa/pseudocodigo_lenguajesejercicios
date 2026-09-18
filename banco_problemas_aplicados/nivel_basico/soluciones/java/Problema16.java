/*
 * Problema 16 - Busqueda de Primer Flanco de Subida
 * int buscaFlanco(double[] arr, int tam)  -> primer i con arr[i] < 0 y arr[i+1] >= 0, o -1
 * El bucle llega hasta tam-2 porque se usa arr[i+1].
 */
import java.util.Scanner;

public class Problema16 {

    static int buscaFlanco(double[] arr, int tam) {
        for (int i = 0; i < tam - 1; i++) {
            if (arr[i] < 0 && arr[i + 1] >= 0) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Voltaje " + i + " (V): ");
            arr[i] = sc.nextDouble();
        }

        int idx = buscaFlanco(arr, tam);
        if (idx < 0) {
            System.out.println("No se detecto ningun flanco de subida.");
        } else {
            System.out.println("Primer flanco de subida entre los indices " + idx + " y " + (idx + 1) + ".");
        }
        sc.close();
    }
}
