/*
 * Problema 15 - Conteo de Muestras Saturadas (Overflow)
 * int cuentaSaturadas(int[] arr, int tam)  -> cuenta cuantas valen 1023 (ADC de 10 bits)
 */
import java.util.Scanner;

public class Problema15 {

    static int cuentaSaturadas(int[] arr, int tam) {
        int contador = 0;
        for (int i = 0; i < tam; i++) {
            if (arr[i] == 1023) {
                contador = contador + 1;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de conversiones: ");
        int tam = sc.nextInt();

        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Conversion " + i + " (0..1023): ");
            arr[i] = sc.nextInt();
        }

        System.out.println("Muestras saturadas (== 1023): " + cuentaSaturadas(arr, tam));
        sc.close();
    }
}
