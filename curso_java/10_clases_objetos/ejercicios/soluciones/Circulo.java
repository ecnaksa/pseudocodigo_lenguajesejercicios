/* Ejercicio 1 - Clase Circulo. */
public class Circulo {
    double radio;

    double area() {
        return 3.14159265 * radio * radio;
    }
    double circunferencia() {
        return 2 * 3.14159265 * radio;
    }

    public static void main(String[] args) {
        Circulo c = new Circulo();
        c.radio = 5;
        System.out.printf("Area: %.4f%n", c.area());
        System.out.printf("Circunferencia: %.4f%n", c.circunferencia());
    }
}
