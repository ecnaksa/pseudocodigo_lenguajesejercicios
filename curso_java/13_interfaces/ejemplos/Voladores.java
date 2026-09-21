/*
 * Interfaz como contrato, implementada por clases no relacionadas por herencia.
 */
interface Volador {
    void volar();
    default void descansar() {           // metodo default (implementacion incluida)
        System.out.println("Descansando en tierra");
    }
}

class Pajaro implements Volador {
    @Override
    public void volar() { System.out.println("El pajaro bate las alas"); }
}

class Avion implements Volador {
    @Override
    public void volar() { System.out.println("El avion enciende motores"); }
}

public class Voladores {
    public static void main(String[] args) {
        Volador[] voladores = { new Pajaro(), new Avion() };
        for (Volador v : voladores) {
            v.volar();          // cada uno segun su clase real
            v.descansar();      // metodo default, compartido
        }
    }
}
