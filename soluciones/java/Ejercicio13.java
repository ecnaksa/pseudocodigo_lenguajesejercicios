/*
 * Ejercicio 13 - Nivel Avanzado
 * boolean esPalindromo(int[] arr, int tam)
 * Determina si un arreglo es simetrico (se lee igual en ambos sentidos).
 */
import java.util.Scanner;

public class Ejercicio13 {

    // En Java el tipo logico se llama 'boolean' (con valores true / false).
    static boolean esPalindromo(int[] arr, int tam) {
        for (int i = 0; i < tam / 2; i++) {
            if (arr[i] != arr[tam - 1 - i]) {
                return false;
            }
        }
        return true;
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

        if (esPalindromo(arr, tam)) {
            System.out.println("El arreglo es simetrico (palindromo).");
        } else {
            System.out.println("El arreglo NO es simetrico.");
        }
        sc.close();
    }
}
