/*
 * Declarar, recorrer y calcular sobre un arreglo. .length da el tamano.
 */
public class Recorrer {
    public static void main(String[] args) {
        int[] notas = {90, 85, 70, 95, 60};

        int suma = 0, maximo = notas[0];
        for (int i = 0; i < notas.length; i++) {
            suma += notas[i];
            if (notas[i] > maximo) maximo = notas[i];
        }

        System.out.println("Cantidad: " + notas.length);
        System.out.println("Suma: " + suma);
        System.out.println("Maximo: " + maximo);
        System.out.printf("Promedio: %.2f%n", (double) suma / notas.length);
    }
}
