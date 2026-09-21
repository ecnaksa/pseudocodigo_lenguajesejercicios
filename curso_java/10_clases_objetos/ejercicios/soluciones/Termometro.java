/* Ejercicio 4 (reto) - Termometro con conversion. */
public class Termometro {
    private double celsius = 0;

    public void set(double c) { celsius = c; }
    public double getCelsius() { return celsius; }
    public double getFahrenheit() { return celsius * 9.0 / 5.0 + 32.0; }

    public static void main(String[] args) {
        Termometro t = new Termometro();
        t.set(25);
        System.out.println(t.getCelsius() + " C = " + t.getFahrenheit() + " F");
    }
}
