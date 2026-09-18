/*
 * Problema 24 - Verificacion de Rango de Histeresis
 * boolean enHisteresis(double[] arr, int tam, double vmin, double vmax)
 * "Estricta": se usan < y > (los extremos NO se permiten).
 */
import java.util.Scanner;

public class Problema24 {

    static boolean enHisteresis(double[] arr, int tam, double vmin, double vmax) {
        for (int i = 0; i < tam; i++) {
            if (!(arr[i] > vmin && arr[i] < vmax)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese el numero de lecturas: ");
        int tam = sc.nextInt();

        double[] arr = new double[tam];
        for (int i = 0; i < tam; i++) {
            System.out.print("Lectura " + i + ": ");
            arr[i] = sc.nextDouble();
        }

        System.out.print("Ingrese Vmin: ");
        double vmin = sc.nextDouble();
        System.out.print("Ingrese Vmax: ");
        double vmax = sc.nextDouble();

        if (enHisteresis(arr, tam, vmin, vmax)) {
            System.out.println("OK: todas las lecturas estan estrictamente dentro del intervalo.");
        } else {
            System.out.println("ALERTA: alguna lectura toca o cruza los limites.");
        }
        sc.close();
    }
}
