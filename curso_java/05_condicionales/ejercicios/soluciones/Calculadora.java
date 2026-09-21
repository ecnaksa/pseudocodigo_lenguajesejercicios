/* Ejercicio 5 (reto) - Calculadora simple con switch. */
import java.util.Scanner;

public class Calculadora {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Primer numero: ");
        double a = sc.nextDouble();
        System.out.print("Operador (+ - * /): ");
        String op = sc.next();
        System.out.print("Segundo numero: ");
        double b = sc.nextDouble();

        switch (op) {
            case "+" -> System.out.println(a + b);
            case "-" -> System.out.println(a - b);
            case "*" -> System.out.println(a * b);
            case "/" -> {
                if (b != 0) System.out.println(a / b);
                else System.out.println("Error: division entre cero");
            }
            default -> System.out.println("Operador desconocido");
        }
        sc.close();
    }
}
