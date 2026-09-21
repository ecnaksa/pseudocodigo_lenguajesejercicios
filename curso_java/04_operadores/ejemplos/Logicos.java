/*
 * Operadores relacionales y logicos: en Java el resultado es boolean.
 */
public class Logicos {
    public static void main(String[] args) {
        int edad = 20;
        boolean tieneEntrada = true;

        System.out.println("edad >= 18: " + (edad >= 18));            // true
        System.out.println("edad == 30: " + (edad == 30));            // false
        System.out.println("mayor Y con entrada: " + (edad >= 18 && tieneEntrada));  // true
        System.out.println("menor O con entrada: " + (edad < 18 || tieneEntrada));   // true
        System.out.println("NO tiene entrada: " + (!tieneEntrada));   // false
    }
}
