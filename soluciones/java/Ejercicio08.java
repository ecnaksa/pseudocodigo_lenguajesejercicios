/*
 * Ejercicio 08 - Nivel Intermedio
 * Almacenar 5 numeros, calcular su promedio, determinar cuantos son mayores
 * que el promedio y desplegar esos valores.
 */
import java.util.Scanner;
import java.util.Locale;

public class Ejercicio08 {

    static void promedioMayores(int[] arr, int tam) {
        int suma = 0;
        for (int i = 0; i < tam; i++) {
            suma = suma + arr[i];
        }

        // (double) fuerza la division real; si ambos fueran int, se perderian los decimales.
        double promedio = (double) suma / tam;
        // Locale.US asegura el punto decimal (no la coma) al formatear.
        System.out.printf(Locale.US, "Promedio: %.2f%n", promedio);

        int mayores = 0;
        System.out.println("Valores mayores al promedio:");
        for (int i = 0; i < tam; i++) {
            if (arr[i] > promedio) {
                mayores = mayores + 1;
                System.out.println(arr[i]);
            }
        }
        System.out.println("Cantidad de elementos mayores al promedio: " + mayores);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 5;
        int[] arr = new int[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Ingrese el elemento " + i + ": ");
            arr[i] = sc.nextInt();
        }
        promedioMayores(arr, tam);
        sc.close();
    }
}
