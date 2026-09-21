/*
 * Tipos primitivos basicos y String, mostrados con println.
 */
public class TiposBasicos {
    public static void main(String[] args) {
        int cantidad = 5;
        double precio = 2.50;
        boolean activo = true;
        char inicial = 'C';
        long distancia = 9000000000L;
        String nombre = "Java";

        System.out.println("Cantidad: " + cantidad);
        System.out.println("Precio: " + precio);
        System.out.println("Activo: " + activo);
        System.out.println("Inicial: " + inicial + " (codigo " + (int) inicial + ")");
        System.out.println("Distancia: " + distancia);
        System.out.println("Nombre: " + nombre);

        var deducido = 42;   // Java infiere int
        System.out.println("var deducido (int): " + deducido);
    }
}
