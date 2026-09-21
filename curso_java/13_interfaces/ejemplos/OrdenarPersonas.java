/*
 * Comparable: implementar compareTo para poder ordenar objetos propios.
 */
import java.util.Arrays;

class Persona implements Comparable<Persona> {
    String nombre;
    int edad;
    public Persona(String nombre, int edad) { this.nombre = nombre; this.edad = edad; }

    @Override
    public int compareTo(Persona otra) {
        return Integer.compare(this.edad, otra.edad);   // ordena por edad
    }
    @Override
    public String toString() { return nombre + "(" + edad + ")"; }
}

public class OrdenarPersonas {
    public static void main(String[] args) {
        Persona[] p = {
            new Persona("Ana", 30),
            new Persona("Luis", 22),
            new Persona("Sara", 27)
        };
        Arrays.sort(p);                       // usa compareTo
        System.out.println(Arrays.toString(p));   // [Luis(22), Sara(27), Ana(30)]
    }
}
