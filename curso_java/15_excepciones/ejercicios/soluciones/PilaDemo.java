/* Ejercicio 4 (reto) - Pila que lanza excepcion al hacer pop() vacia. */
class Pila {
    private int[] datos = new int[100];
    private int tope = 0;

    public void push(int v) { datos[tope++] = v; }
    public int pop() {
        if (tope == 0) throw new RuntimeException("pila vacia");
        return datos[--tope];
    }
}

public class PilaDemo {
    public static void main(String[] args) {
        Pila p = new Pila();
        p.push(10);
        System.out.println(p.pop());    // 10

        try {
            p.pop();                    // vacia -> lanza
        } catch (RuntimeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
