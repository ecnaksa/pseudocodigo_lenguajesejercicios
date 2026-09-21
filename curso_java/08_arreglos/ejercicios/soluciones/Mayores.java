/* Ejercicio 5 (reto) - Contar cuantos superan el promedio. */
public class Mayores {
    public static void main(String[] args) {
        int[] a = {5, 20, 8, 15, 2, 30};

        int suma = 0;
        for (int x : a) suma += x;
        double promedio = (double) suma / a.length;

        int mayores = 0;
        for (int x : a) if (x > promedio) mayores++;

        System.out.printf("Promedio: %.2f%n", promedio);
        System.out.println("Superan el promedio: " + mayores);
    }
}
