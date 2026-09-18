/*
 * Ejercicio 12 - Nivel Avanzado
 * void invierteArreglo(int[] arr, int tam)
 * Modifica el orden de los elementos de manera que queden invertidos.
 */
import java.util.Scanner;

public class Ejercicio12 {

    // En Java el arreglo se pasa por referencia: los cambios se ven en main.
    static void invierteArreglo(int[] arr, int tam) {
        for (int i = 0; i < tam / 2; i++) {
            int aux = arr[i];
            arr[i] = arr[tam - 1 - i];
            arr[tam - 1 - i] = aux;
        }
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

        invierteArreglo(arr, tam);

        System.out.println("El nuevo arreglo (invertido) es:");
        for (int i = 0; i < tam; i++) {
            System.out.println(arr[i]);
        }
        sc.close();
    }
}
