/*
 * El operador + con texto: concatenacion (y el orden importa).
 */
public class Concatenacion {
    public static void main(String[] args) {
        System.out.println("Total: " + 5);            // Total: 5
        System.out.println("Suma: " + 3 + 4);          // Suma: 34  (3 y 4 se concatenan)
        System.out.println("Suma: " + (3 + 4));        // Suma: 7   (parentesis primero)

        int cantidad = 3;
        double precio = 2.5;
        System.out.println("Compra: " + cantidad + " x " + precio + " = " + (cantidad * precio));
    }
}
