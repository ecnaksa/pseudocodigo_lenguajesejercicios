/*
 * Paso por valor: un primitivo no cambia afuera; el contenido de un arreglo si.
 */
import java.util.Arrays;

public class PorValor {

    static void intentarCambiar(int x) {
        x = 100;                         // solo la copia local
    }
    static void duplicarTodos(int[] arr) {
        for (int i = 0; i < arr.length; i++) arr[i] *= 2;   // modifica el arreglo original
    }

    public static void main(String[] args) {
        int n = 5;
        intentarCambiar(n);
        System.out.println("n = " + n);              // 5 (no cambio)

        int[] datos = {1, 2, 3};
        duplicarTodos(datos);
        System.out.println("datos = " + Arrays.toString(datos));  // [2, 4, 6]
    }
}
