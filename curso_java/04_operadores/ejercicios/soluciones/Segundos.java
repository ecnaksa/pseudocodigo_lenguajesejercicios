/* Ejercicio 2 - Descomponer segundos en minutos y segundos. */
import java.util.Scanner;

public class Segundos {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Segundos: ");
        int total = sc.nextInt();

        int minutos = total / 60;
        int segundos = total % 60;
        System.out.println(total + " segundos = " + minutos + " min y " + segundos + " s");
        sc.close();
    }
}
