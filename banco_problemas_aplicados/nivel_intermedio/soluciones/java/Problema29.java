/*
 * Problema 29 - Suma de Matriz de Nodos por Filas
 * En Java una matriz es un arreglo de arreglos (double[][]) que conoce sus dimensiones:
 * mat.length filas, mat[i].length columnas. (Ver teoria/02_matrices_2d.md)
 */
import java.util.Scanner;
import java.util.Locale;

public class Problema29 {

    static double[] sumaFilas(double[][] mat) {
        double[] res = new double[mat.length];
        for (int i = 0; i < mat.length; i++) {
            double suma = 0.0;
            for (int j = 0; j < mat[i].length; j++) {
                suma = suma + mat[i][j];
            }
            res[i] = suma;
        }
        return res;
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

        double[] res = sumaFilas(mat);

        System.out.println("Suma por filas:");
        for (int i = 0; i < n; i++) {
            System.out.printf(Locale.US, "  fila %d = %.2f%n", i, res[i]);
        }
        sc.close();
    }
}
