/*
 * Problema 06 - Frecuencia de Falla Especifica en PLC
 * int cuentaRepeticiones(int[] arr, int x, int tam)
 */
import java.util.Scanner;

public class Problema06 {

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
        System.out.print("Ingrese el numero de registros: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Registro " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.print("Ingrese el codigo de error a rastrear (x): ");
        int x = sc.nextInt();

        System.out.println("El codigo " + x + " se repite " + cuentaRepeticiones(arr, x, tam) + " veces.");
        sc.close();
    }
}
