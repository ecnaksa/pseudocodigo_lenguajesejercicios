/*
 * Ejercicio 15 - Nivel Avanzado
 * int eliminaDuplicados(int[] arr, int tam)
 * Remueve los elementos duplicados y devuelve el nuevo tamano logico.
 *
 * Nota: el arreglo en Java conserva su longitud fisica (arr.length = 8); lo que
 * cambia es el tamano LOGICO devuelto, que indica cuantas posiciones son validas.
 */
import java.util.Scanner;

public class Ejercicio15 {

    static int eliminaDuplicados(int[] arr, int tam) {
        for (int i = 0; i < tam; i++) {
            for (int j = i + 1; j < tam; j++) {
                if (arr[i] == arr[j]) {
                    for (int k = j; k < tam - 1; k++) {
                        arr[k] = arr[k + 1];
                    }
                    tam = tam - 1;
                    j = j - 1;
                }
            }
        }
        return tam;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 8;
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }

        int ntam = eliminaDuplicados(arr, tam);

        System.out.print("Arreglo sin duplicados (" + ntam + " elementos): ");
        for (int i = 0; i < ntam; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
