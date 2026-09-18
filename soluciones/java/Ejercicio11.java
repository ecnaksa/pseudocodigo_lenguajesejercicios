/*
 * Ejercicio 11 - Nivel Intermedio
 * Llenar un vector de 20 elementos e imprimir la posicion y el valor del mayor.
 */
import java.util.Scanner;

public class Ejercicio11 {

    static void encontrarMayor(int[] arr, int tam) {
        int mayor = arr[0];
        int posicion = 0;
        for (int i = 1; i < tam; i++) {
            if (arr[i] > mayor) {
                mayor = arr[i];
                posicion = i;
            }
        }
        System.out.println("El elemento mayor es: " + mayor);
        System.out.println("Se encuentra en la posicion: " + posicion);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 20;
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }
        encontrarMayor(arr, tam);
        sc.close();
    }
}
