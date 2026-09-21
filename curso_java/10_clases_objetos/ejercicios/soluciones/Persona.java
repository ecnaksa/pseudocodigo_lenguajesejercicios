/* Ejercicio 3 - Persona con getters/setters y validacion. */
public class Persona {
    private String nombre;
    private int edad = 0;

    public void setNombre(String nombre) { this.nombre = nombre; }
    public String getNombre() { return nombre; }

    public void setEdad(int edad) {
        if (edad >= 0) this.edad = edad;
        else System.out.println("Edad invalida");
    }
    public int getEdad() { return edad; }

    public static void main(String[] args) {
        Persona p = new Persona();
        p.setNombre("Ana");
        p.setEdad(25);
        p.setEdad(-3);                    // rechazado
        System.out.println(p.getNombre() + ", " + p.getEdad() + " anios");
    }
}
