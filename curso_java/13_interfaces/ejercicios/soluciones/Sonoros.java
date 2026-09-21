/* Ejercicio 2 - Interfaz Sonoro. */
interface Sonoro {
    String sonido();
}

class Perro implements Sonoro {
    @Override
    public String sonido() { return "Guau"; }
}

class Campana implements Sonoro {
    @Override
    public String sonido() { return "Din don"; }
}

public class Sonoros {
    public static void main(String[] args) {
        Sonoro[] cosas = { new Perro(), new Campana() };
        for (Sonoro s : cosas) {
            System.out.println(s.sonido());
        }
    }
}
