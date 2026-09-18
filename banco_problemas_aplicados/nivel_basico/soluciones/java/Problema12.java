/*
 * Problema 12 - Verificacion de Rango de Operacion Segura
 * boolean enRango(double[] arr, int tam)  -> true si TODAS estan en [3.3, 5.0]
 * Recuerda: "3.3 <= val <= 5.0" se escribe (val >= 3.3 && val <= 5.0).
 */
import java.util.Scanner;

public class Problema12 {

    static boolean enRango(double[] arr, int tam) {
        for (int i = 0; i < tam; i++) {
            if (!(arr[i] >= 3.3 && arr[i] <= 5.0)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam = 10;
        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Medicion " + i + " (V): ");
            arr[i] = sc.nextDouble();
        }

        if (enRango(arr, tam)) {
            System.out.println("OK: todas las mediciones estan dentro del rango seguro [3.3, 5.0].");
        } else {
            System.out.println("ALERTA: al menos una medicion esta fuera del rango [3.3, 5.0].");
        }
        sc.close();
    }
}
