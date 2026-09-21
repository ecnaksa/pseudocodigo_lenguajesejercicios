/*
 * Operadores aritmeticos, con enfasis en / (division) y % (residuo).
 */
public class Aritmeticos {
    public static void main(String[] args) {
        int a = 17, b = 5;
        System.out.println(a + " + " + b + " = " + (a + b));
        System.out.println(a + " - " + b + " = " + (a - b));
        System.out.println(a + " * " + b + " = " + (a * b));
        System.out.println(a + " / " + b + " = " + (a / b) + " (division entera)");
        System.out.println(a + " % " + b + " = " + (a % b) + " (residuo)");

        System.out.println("2 + 3 * 4 = " + (2 + 3 * 4));       // 14
        System.out.println("(2 + 3) * 4 = " + ((2 + 3) * 4));   // 20
    }
}
