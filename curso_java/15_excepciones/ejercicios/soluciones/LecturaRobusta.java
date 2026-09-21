/* Ejercicio 3 - Atrapar NumberFormatException al convertir texto a numero. */
public class LecturaRobusta {
    public static void main(String[] args) {
        String[] entradas = {"42", "abc", "100", "3.5", "-7"};
        int suma = 0;
        for (String s : entradas) {
            try {
                int n = Integer.parseInt(s);
                suma += n;
                System.out.println("Convertido: " + n);
            } catch (NumberFormatException e) {
                System.out.println("No es un entero valido: \"" + s + "\"");
            }
        }
        System.out.println("Suma de los validos: " + suma);
    }
}
