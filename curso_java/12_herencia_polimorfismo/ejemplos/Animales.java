/*
 * Herencia (extends, super) y polimorfismo con @Override.
 * La clase publica (Animales) tiene el main; las demas van en el mismo archivo.
 */
class Animal {
    protected String nombre;

    public Animal(String nombre) {
        this.nombre = nombre;
    }
    public void hacerSonido() {
        System.out.println(nombre + ": sonido generico");
    }
}

class Perro extends Animal {
    public Perro(String nombre) { super(nombre); }
    @Override
    public void hacerSonido() { System.out.println(nombre + ": Guau"); }
}

class Gato extends Animal {
    public Gato(String nombre) { super(nombre); }
    @Override
    public void hacerSonido() { System.out.println(nombre + ": Miau"); }
}

public class Animales {
    public static void main(String[] args) {
        Animal[] animales = {
            new Perro("Rex"),
            new Gato("Michi"),
            new Animal("Bestia")
        };
        for (Animal a : animales) {
            a.hacerSonido();     // cada uno responde segun su tipo real
        }
    }
}
