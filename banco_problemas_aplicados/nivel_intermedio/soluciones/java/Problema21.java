/*
 * Problema 21 - Pico Maximo y Su Indice Modular
 * Java no tiene punteros ni referencias como C/C++. Para "devolver" tambien el indice se usa
 * un arreglo de un elemento como parametro de salida (pos[0]), que SI se modifica desde el
 * metodo porque los arreglos se pasan por referencia. (Ver teoria/01_devolver_varios_valores.md)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema21 {

    static double picoMaximo(double[] arr, int tam, int[] pos) {
        double mayor = arr[0];
        pos[0] = 0;
        for (int i = 1; i < tam; i++) {
            if (arr[i] > mayor) {
                mayor = arr[i];
                pos[0] = i;
            }
        }
        return mayor;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 20;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Muestra " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        int[] posicion = new int[1];               // "caja" para el parametro de salida
        double valor = picoMaximo(arr, tam, posicion);
        System.out.printf(Locale.US, "Pico maximo: %.2f%n", valor);
        System.out.println("Indice de muestreo: " + posicion[0]);
        sc.close();
    }
}
