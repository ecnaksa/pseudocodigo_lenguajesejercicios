/*
 * Ejercicio 01 - Nivel Basico
 * int sumaElementos(int[] arr, int tam)
 * Recibe un arreglo de enteros y regresa el resultado de sumar todos sus elementos.
 */
import java.util.Scanner;

public class Ejercicio01 {

    // Los metodos que no pertenecen a un objeto se declaran 'static'.
    static int sumaElementos(int[] arr, int tam) {
        int suma = 0;
        for (int i = 0; i < tam; i++) {
            suma = suma + arr[i];
        }
        return suma;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el tamano del arreglo: ");
        int tam = sc.nextInt();

        // En Java el arreglo se crea con 'new' y conoce su propia longitud (arr.length).
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }

        System.out.println("La suma de los elementos del arreglo es: " + sumaElementos(arr, tam));
        sc.close();
    }
}
