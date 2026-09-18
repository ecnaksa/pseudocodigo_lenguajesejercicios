/*
 * Problema 31 - Busqueda de Fila con Mayor Consumo
 * Devuelve el indice de la fila cuya suma es la mayor.
 */
import java.util.Scanner;

public class Problema31 {

    static int filaMayorConsumo(double[][] mat) {
        int filaMax = 0;
        double mayorSuma = 0.0;
        for (int j = 0; j < mat[0].length; j++) {
            mayorSuma = mayorSuma + mat[0][j];
        }
        for (int i = 1; i < mat.length; i++) {
            double suma = 0.0;
            for (int j = 0; j < mat[i].length; j++) {
                suma = suma + mat[i][j];
            }
            if (suma > mayorSuma) {
                mayorSuma = suma;
                filaMax = i;
            }
        }
        return filaMax;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Numero de buses/filas (N): ");
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

        System.out.println("La fila con mayor consumo es la " + filaMayorConsumo(mat) + ".");
        sc.close();
    }
}
