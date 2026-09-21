/* Ejercicio 2 - Clase Contador con estado privado. */
public class Contador {
    private int valor = 0;

    public void incrementar() { valor++; }
    public void reiniciar()   { valor = 0; }
    public int  obtener()     { return valor; }

    public static void main(String[] args) {
        Contador c = new Contador();
        c.incrementar();
        c.incrementar();
        c.incrementar();
        System.out.println("Valor: " + c.obtener());   // 3
        c.reiniciar();
        System.out.println("Tras reiniciar: " + c.obtener());  // 0
    }
}
