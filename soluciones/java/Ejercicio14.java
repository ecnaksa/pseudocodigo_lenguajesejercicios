/*
 * Ejercicio 14 - Nivel Avanzado
 * void ordenaBurbuja(int[] arr, int tam)
 * Ordena el arreglo de forma ascendente con el metodo de la burbuja.
 */
import java.util.Scanner;

public class Ejercicio14 {

    static void ordenaBurbuja(int[] arr, int tam) {
        for (int i = 0; i < tam; i++) {
            for (int f = 0; f < tam - 1 - i; f++) {
                if (arr[f] > arr[f + 1]) {
                    int aux = arr[f];
                    arr[f] = arr[f + 1];
                    arr[f + 1] = aux;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 5;
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }

        ordenaBurbuja(arr, tam);

        System.out.print("El arreglo ordenado es: ");
        for (int i = 0; i < tam; i++) {
            // "Escribir sin saltar": print (sin ln) no agrega salto de linea.
            System.out.print(arr[i] + " ");
        }
        System.out.println();   // Un unico salto de linea al final.
        sc.close();
    }
}
