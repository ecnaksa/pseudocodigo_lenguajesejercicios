/*
 * Ejercicio 04 - Nivel Basico
 * int buscaElemento(int[] arr, int x, int tam)
 * Busca x y regresa su posicion, o -1 si no se encuentra.
 */
import java.util.Scanner;

public class Ejercicio04 {

    static int buscaElemento(int[] arr, int x, int tam) {
        for (int i = 0; i < tam; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
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

        System.out.print("Ingrese el elemento a buscar: ");
        int x = sc.nextInt();

        int pos = buscaElemento(arr, x, tam);
        if (pos < 0) {
            System.out.println("No existe elemento coincidente.");
        } else {
            System.out.println("La posicion del elemento es: " + pos);
        }
        sc.close();
    }
}
