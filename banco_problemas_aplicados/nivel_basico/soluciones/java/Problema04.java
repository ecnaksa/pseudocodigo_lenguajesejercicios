/*
 * Problema 04 - Codigo de Error en Buffer
 * int buscaElemento(int[] arr, int x, int tam)  -> posicion de x, o -1
 */
import java.util.Scanner;

public class Problema04 {

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
        System.out.print("Ingrese el tamano del buffer: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Estado " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.print("Ingrese el codigo de falla a buscar: ");
        int x = sc.nextInt();

        int pos = buscaElemento(arr, x, tam);
        if (pos < 0) {
            System.out.println("El codigo " + x + " no aparece en el buffer.");
        } else {
            System.out.println("El codigo " + x + " esta en la posicion: " + pos);
        }
        sc.close();
    }
}
