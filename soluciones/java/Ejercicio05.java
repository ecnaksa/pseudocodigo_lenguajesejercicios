/*
 * Ejercicio 05 - Nivel Intermedio
 * int sumaPares(int[] arr, int tam)
 * Regresa la suma de solo los numeros pares del arreglo.
 */
import java.util.Scanner;

public class Ejercicio05 {

    static int sumaPares(int[] arr, int tam) {
        int suma = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] % 2 == 0) {
                suma = suma + arr[i];
            }
        }
        return suma;
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

        System.out.println("La suma de los numeros pares es: " + sumaPares(arr, tam));
        sc.close();
    }
}
