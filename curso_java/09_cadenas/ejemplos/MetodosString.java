/*
 * Metodos utiles de String. Recuerda: los metodos devuelven NUEVAS cadenas.
 */
public class MetodosString {
    public static void main(String[] args) {
        String s = "Hola Mundo";

        System.out.println("Longitud: " + s.length());        // 10
        System.out.println("Caracter 0: " + s.charAt(0));      // H
        System.out.println("substring(5): " + s.substring(5)); // Mundo
        System.out.println("substring(0,4): " + s.substring(0, 4)); // Hola
        System.out.println("indexOf Mundo: " + s.indexOf("Mundo")); // 5
        System.out.println("contains Hola: " + s.contains("Hola"));  // true
        System.out.println("Mayusculas: " + s.toUpperCase());  // HOLA MUNDO
        System.out.println("Reemplazo: " + s.replace("Mundo", "Java"));

        String[] partes = s.split(" ");
        System.out.println("Partes: " + partes.length + " -> " + partes[0] + " / " + partes[1]);
    }
}
