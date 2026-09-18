/*
 * Ejercicio 06 - Nivel Intermedio
 * int cuentaRepeticiones(int[] arr, int x, int tam)
 * Regresa el numero de veces que se repite el valor x dentro del arreglo.
 */
import java.util.Scanner;

public class Ejercicio06 {

    static int cuentaRepeticiones(int[] arr, int x, int tam) {
        int contador = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] == x) {
                contador = contador + 1;
            }
        }
        return contador;
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

        System.out.print("Ingrese el valor a contar (x): ");
        int x = sc.nextInt();

        System.out.println("El valor " + x + " se repite " + cuentaRepeticiones(arr, x, tam) + " veces.");
        sc.close();
    }
}
