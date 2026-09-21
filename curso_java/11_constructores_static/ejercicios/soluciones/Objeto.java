/* Ejercicio 4 (reto) - Contador de instancias con static. */
public class Objeto {
    static int vivos = 0;

    public Objeto() {
        vivos++;
    }

    public static void main(String[] args) {
        new Objeto();
        new Objeto();
        Objeto tercero = new Objeto();
        System.out.println("Vivos: " + Objeto.vivos);   // 3
        System.out.println("Tercero creado: " + (tercero != null));
    }
}
