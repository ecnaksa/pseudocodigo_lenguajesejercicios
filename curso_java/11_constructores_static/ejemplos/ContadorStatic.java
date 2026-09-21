/*
 * Miembro static compartido: contar cuantos objetos se crean.
 */
public class ContadorStatic {
    static int total = 0;        // compartido por toda la clase

    public ContadorStatic() {
        total++;
    }

    public static void main(String[] args) {
        new ContadorStatic();
        new ContadorStatic();
        new ContadorStatic();
        System.out.println("Objetos creados: " + ContadorStatic.total);   // 3
    }
}
