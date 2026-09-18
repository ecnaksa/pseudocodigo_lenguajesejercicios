/*
 * Problema 22 - Conteo Avanzado de Codigos de Falla
 * int contarFalla(int[] arr, int tam, int codigo)
 */
import java.util.Scanner;

public class Problema22 {

    static int contarFalla(int[] arr, int tam, int codigo) {
        int contador = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] == codigo) {
                contador = contador + 1;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de fallas registradas: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Falla " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.print("Ingrese el codigo a cuantificar: ");
        int codigo = sc.nextInt();

        System.out.println("El codigo " + codigo + " aparece " + contarFalla(arr, tam, codigo) + " veces.");
        sc.close();
    }
}
