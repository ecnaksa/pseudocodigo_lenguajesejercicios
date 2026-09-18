/*
 * Problema 03 - Deteccion de Transitorios Impares
 * int cuentaImpares(int[] arr, int tam)  -> cuenta muestras en INDICES impares (i % 2 != 0)
 * (condicion sobre el indice, no sobre el valor; por eso no se lee el contenido)
 */
import java.util.Scanner;

public class Problema03 {

    static int cuentaImpares(int[] arr, int tam) {
        int contador = 0;
        for (int i = 0; i < tam; i++) {
            if (i % 2 != 0) {
                contador = contador + 1;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de muestras: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Muestra " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.println("Muestras en indices impares: " + cuentaImpares(arr, tam));
        sc.close();
    }
}
