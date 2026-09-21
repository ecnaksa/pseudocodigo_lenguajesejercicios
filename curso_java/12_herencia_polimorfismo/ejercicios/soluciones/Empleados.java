/* Ejercicio 1 - Empleado y Gerente. */
class Empleado {
    protected String nombre;
    protected double basico;
    public Empleado(String nombre, double basico) {
        this.nombre = nombre;
        this.basico = basico;
    }
    public double salario() { return basico; }
    public String getNombre() { return nombre; }
}

class Gerente extends Empleado {
    private double bono;
    public Gerente(String nombre, double basico, double bono) {
        super(nombre, basico);
        this.bono = bono;
    }
    @Override
    public double salario() { return basico + bono; }
}

public class Empleados {
    public static void main(String[] args) {
        Empleado e = new Empleado("Ana", 1000);
        Gerente g = new Gerente("Luis", 1000, 500);
        System.out.println(e.getNombre() + ": " + e.salario());   // 1000
        System.out.println(g.getNombre() + ": " + g.salario());   // 1500
    }
}
