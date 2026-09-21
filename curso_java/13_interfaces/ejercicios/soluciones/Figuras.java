/* Ejercicio 1 - Interfaz Figura implementada por Circulo y Cuadrado. */
interface Figura {
    double area();
}

class Circulo implements Figura {
    double r;
    public Circulo(double r) { this.r = r; }
    @Override
    public double area() { return 3.14159265 * r * r; }
}

class Cuadrado implements Figura {
    double lado;
    public Cuadrado(double lado) { this.lado = lado; }
    @Override
    public double area() { return lado * lado; }
}

public class Figuras {
    public static void main(String[] args) {
        Figura[] figuras = { new Circulo(2), new Cuadrado(4) };
        for (Figura f : figuras) {
            System.out.printf("Area: %.4f%n", f.area());
        }
    }
}
