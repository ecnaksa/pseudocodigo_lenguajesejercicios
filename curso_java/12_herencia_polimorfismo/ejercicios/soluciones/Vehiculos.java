/* Ejercicio 3 (reto) - Vehiculos polimorficos. */
class Vehiculo {
    protected String marca;
    public Vehiculo(String marca) { this.marca = marca; }
    public void describir() { System.out.println("Vehiculo " + marca); }
}

class Coche extends Vehiculo {
    public Coche(String marca) { super(marca); }
    @Override
    public void describir() { System.out.println("Coche " + marca + " (4 ruedas)"); }
}

class Moto extends Vehiculo {
    public Moto(String marca) { super(marca); }
    @Override
    public void describir() { System.out.println("Moto " + marca + " (2 ruedas)"); }
}

public class Vehiculos {
    public static void main(String[] args) {
        Vehiculo[] v = { new Coche("Toyota"), new Moto("Honda"), new Vehiculo("Generico") };
        for (Vehiculo x : v) x.describir();
    }
}
