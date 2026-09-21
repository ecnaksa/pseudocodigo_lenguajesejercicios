/* Ejercicio 3 (reto) - Producto Comparable por precio. */
import java.util.Arrays;

class Producto implements Comparable<Producto> {
    String nombre;
    double precio;
    public Producto(String nombre, double precio) { this.nombre = nombre; this.precio = precio; }

    @Override
    public int compareTo(Producto otro) {
        return Double.compare(this.precio, otro.precio);   // ordena por precio
    }
    @Override
    public String toString() { return nombre + "($" + precio + ")"; }
}

public class Productos {
    public static void main(String[] args) {
        Producto[] p = {
            new Producto("Cafe", 3.50),
            new Producto("Pan", 1.20),
            new Producto("Leche", 2.00)
        };
        Arrays.sort(p);
        System.out.println(Arrays.toString(p));   // [Pan($1.2), Leche($2.0), Cafe($3.5)]
    }
}
