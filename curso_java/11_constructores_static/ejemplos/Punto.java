/*
 * Constructores (sobrecargados y encadenados con this()) y toString().
 */
public class Punto {
    double x, y;

    public Punto() {
        this(0, 0);              // llama al otro constructor
    }
    public Punto(double x, double y) {
        this.x = x;              // this distingue atributo de parametro
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
        Punto a = new Punto();        // (0, 0)
        Punto b = new Punto(3, 4);    // (3, 4)
        System.out.println("a = " + a);   // usa toString: (0.0, 0.0)
        System.out.println("b = " + b);   // (3.0, 4.0)
    }
}
