/*
 * Problema 30 - Transposicion de Matriz de Admitancias
 * Devuelve la transpuesta M x N:  Trans[j][i] = Mat[i][j].
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema30 {

    static double[][] transpone(double[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        double[][] trans = new double[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                trans[j][i] = mat[i][j];
            }
        }
        return trans;
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

        double[][] trans = transpone(mat);

        System.out.println("Matriz transpuesta (" + m + " x " + n + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf(Locale.US, "%.2f ", trans[i][j]);
            }
            System.out.println();
        }
        sc.close();
    }
}
