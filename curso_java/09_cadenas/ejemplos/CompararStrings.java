/*
 * Comparar cadenas: usa equals(), no ==.
 */
public class CompararStrings {
    public static void main(String[] args) {
        String a = "hola";
        String c = new String("hola");   // fuerza un objeto distinto

        System.out.println("a == c:        " + (a == c));        // false (objetos distintos)
        System.out.println("a.equals(c):   " + a.equals(c));     // true  (mismo contenido)
        System.out.println("equalsIgnoreCase HOLA: " + a.equalsIgnoreCase("HOLA")); // true

        // La inmutabilidad: hay que reasignar
        String s = "texto";
        s.toUpperCase();               // se descarta
        System.out.println("sin reasignar: " + s);   // texto
        s = s.toUpperCase();           // ahora si
        System.out.println("reasignado:    " + s);   // TEXTO
    }
}
