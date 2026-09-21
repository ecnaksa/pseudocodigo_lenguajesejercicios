/*
 * println vs print, y secuencias de escape (\n salto de linea, \t tabulacion).
 */
public class VariasLineas {
    public static void main(String[] args) {
        System.out.println("Aprendiendo Java");
        System.out.println("Linea 1");
        System.out.println("Linea 2");

        System.out.print("Sin ");        // print NO salta de linea
        System.out.print("salto\n");     // \n hace el salto manualmente

        System.out.println("Nombre:\tEdad:");   // \t = tabulacion
        System.out.println("Ana\t25");
        System.out.println("Comilla \" y barra \\");
    }
}
