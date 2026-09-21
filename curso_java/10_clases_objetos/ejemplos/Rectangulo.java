/*
 * Una clase con atributos y metodos de instancia, mas un main para probarla.
 */
public class Rectangulo {
    double base;      // atributos: cada objeto tiene los suyos
    double altura;

    double area() {                 // metodo de instancia
        return base * altura;
    }
    double perimetro() {
        return 2 * (base + altura);
    }

    public static void main(String[] args) {
        Rectangulo r = new Rectangulo();   // crear un objeto
        r.base = 4;
        r.altura = 3;
        System.out.println("Area: " + r.area());            // 12
        System.out.println("Perimetro: " + r.perimetro());  // 14

        Rectangulo otro = new Rectangulo();
        otro.base = 10;
        otro.altura = 2;
        System.out.println("Area del otro: " + otro.area()); // 20 (objeto independiente)
    }
}
