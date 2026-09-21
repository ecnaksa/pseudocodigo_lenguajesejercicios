/* Ejercicio 1 - Maximo y minimo de un arreglo. */
public class MaxMin {
    public static void main(String[] args) {
        int[] a = {23, 8, 45, 12, 4, 30};

        int maximo = a[0], minimo = a[0];
        for (int x : a) {
            if (x > maximo) maximo = x;
            if (x < minimo) minimo = x;
        }
        System.out.println("Maximo: " + maximo);
        System.out.println("Minimo: " + minimo);
    }
}
