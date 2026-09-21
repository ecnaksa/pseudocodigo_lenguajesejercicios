/*
 * Clase abstracta como plantilla: toda Figura debe implementar area().
 */
abstract class Figura {
    abstract double area();          // metodo abstracto (sin cuerpo)
}

class Circulo extends Figura {
    double r;
    public Circulo(double r) { this.r = r; }
    @Override
    double area() { return 3.14159265 * r * r; }
}

class Rectangulo extends Figura {
    double base, altura;
    public Rectangulo(double base, double altura) { this.base = base; this.altura = altura; }
    @Override
    double area() { return base * altura; }
}

public class Figuras {
    public static void main(String[] args) {
        Figura[] figuras = {
            new Circulo(2),
            new Rectangulo(3, 4)
        };
        for (Figura f : figuras) {
            System.out.printf("Area: %.4f%n", f.area());   // 12.566..., 12
        }
    }
}
