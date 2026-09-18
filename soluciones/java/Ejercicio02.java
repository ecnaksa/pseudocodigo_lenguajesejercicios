/*
 * Ejercicio 02 - Nivel Basico
 * int buscaMinimo(int[] arr, int tam)
 * Recibe un arreglo de enteros y regresa el valor minimo almacenado.
 */
import java.util.Scanner;

public class Ejercicio02 {

    static int buscaMinimo(int[] arr, int tam) {
        int min = arr[0];
        for (int i = 1; i < tam; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del arreglo: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.println("El valor minimo es: " + buscaMinimo(arr, tam));
        sc.close();
    }
}
