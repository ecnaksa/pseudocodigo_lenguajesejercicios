/* Ejercicio 2 - Clase abstracta Forma y derivadas. */
abstract class Forma {
    abstract double area();
}

class Cuadrado extends Forma {
    double lado;
    public Cuadrado(double lado) { this.lado = lado; }
    @Override
    double area() { return lado * lado; }
}

class Triangulo extends Forma {
    double base, altura;
    public Triangulo(double base, double altura) { this.base = base; this.altura = altura; }
    @Override
    double area() { return base * altura / 2.0; }
}

public class Formas {
    public static void main(String[] args) {
        Forma[] formas = { new Cuadrado(4), new Triangulo(3, 6) };
        for (Forma f : formas) {
            System.out.println("Area: " + f.area());   // 16.0, 9.0
        }
    }
}
