/*
 * Matriz (arreglo 2D) recorrida con dos bucles anidados.
 */
public class Matriz {
    public static void main(String[] args) {
        int[][] m = {
            {1, 2, 3},
            {4, 5, 6}
        };

        for (int i = 0; i < m.length; i++) {          // filas
            for (int j = 0; j < m[i].length; j++) {   // columnas de la fila i
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
        }
    }
}
