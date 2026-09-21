/*
 * Bucles anidados: tabla de multiplicar del 1 al 5.
 */
public class TablaAnidada {
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                System.out.printf("%4d", i * j);   // %4d alinea en ancho 4
            }
            System.out.println();                   // nueva fila
        }
    }
}
