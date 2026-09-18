/*
 * Ejercicio 07 - Nivel Intermedio
 * Almacenar 10 numeros enteros. Imprimir cuantos son ceros, negativos y positivos,
 * ademas de la suma de los negativos y la suma de los positivos.
 */
import java.util.Scanner;

public class Ejercicio07 {

    static void analizarArreglo(int[] arr, int tam) {
        int ceros = 0, pos = 0, neg = 0, spos = 0, sneg = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] == 0) {
                ceros = ceros + 1;
            } else if (arr[i] < 0) {
                neg = neg + 1;
                sneg = sneg + arr[i];
            } else {
                pos = pos + 1;
                spos = spos + arr[i];
            }
        }
        System.out.println("Cantidad de ceros: " + ceros);
        System.out.println("Cantidad de positivos: " + pos);
        System.out.println("Cantidad de negativos: " + neg);
        System.out.println("Suma de los positivos: " + spos);
        System.out.println("Suma de los negativos: " + sneg);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 10;
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }
        analizarArreglo(arr, tam);
        sc.close();
    }
}
