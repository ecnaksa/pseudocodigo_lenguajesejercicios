/* Ejercicio 5 (reto) - Caracter y su codigo. */
public class Ascii {
    public static void main(String[] args) {
        char letra = 'Z';
        System.out.println("Caracter: " + letra);
        System.out.println("Codigo: " + (int) letra);
        System.out.println("Siguiente: " + (char) (letra + 1));   // '['
    }
}
