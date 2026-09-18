/*
 * Problema 32 - Conteo de Nodos con Voltaje Critico
 * Cuenta cuantas celdas de la matriz superan un umbral.
 */
import java.util.Scanner;

public class Problema32 {

    static int cuentaCriticos(double[][] mat, double umbral) {
        int contador = 0;
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] > umbral) {
                    contador = contador + 1;
                }
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero de filas (N): ");
        int n = sc.nextInt();
        System.out.print("Numero de columnas (M): ");
        int m = sc.nextInt();

        double[][] mat = new double[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print("mat[" + i + "][" + j + "]: ");
                mat[i][j] = sc.nextDouble();
            }
        }

        System.out.print("Umbral critico de sobretension: ");
        double umbral = sc.nextDouble();

        System.out.println("Nodos que superan el umbral: " + cuentaCriticos(mat, umbral));
        sc.close();
    }
}
