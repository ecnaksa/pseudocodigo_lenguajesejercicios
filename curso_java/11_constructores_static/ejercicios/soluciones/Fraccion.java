/* Ejercicio 1 - Fraccion con constructores sobrecargados y toString. */
public class Fraccion {
    private int numerador;
    private int denominador;

    public Fraccion(int numerador) {
        this(numerador, 1);          // denominador 1 por defecto
    }
    public Fraccion(int numerador, int denominador) {
        this.numerador = numerador;
        this.denominador = denominador;
    }

    public double valor() {
        if (denominador == 0) return 0;
        return (double) numerador / denominador;
    }

    @Override
    public String toString() {
        return numerador + "/" + denominador;
    }

    public static void main(String[] args) {
        Fraccion media = new Fraccion(1, 2);
        Fraccion entero = new Fraccion(5);
        System.out.println(media + " = " + media.valor());     // 1/2 = 0.5
        System.out.println(entero + " = " + entero.valor());   // 5/1 = 5.0
    }
}
