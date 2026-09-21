/* Ejercicio 3 - Promedio de un arreglo con un metodo. */
public class PromedioArr {
    static double promedio(int[] arr) {
        int suma = 0;
        for (int x : arr) suma += x;
        return (double) suma / arr.length;
    }
    public static void main(String[] args) {
        int[] datos = {10, 20, 30, 40};
        System.out.printf("Promedio: %.2f%n", promedio(datos));
    }
}
