/*
 * Ejercicio 03 - Nivel Basico
 * int cuentaImpares(int[] arr, int tam)
 * Regresa la cantidad total de numeros impares que contiene el arreglo.
 */
import java.util.Scanner;

public class Ejercicio03 {

    static int cuentaImpares(int[] arr, int tam) {
        int nimpar = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] % 2 != 0) {
                nimpar = nimpar + 1;
            }
        }
        return nimpar;
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

        System.out.println("La cantidad de numeros impares es: " + cuentaImpares(arr, tam));
        sc.close();
    }
}
