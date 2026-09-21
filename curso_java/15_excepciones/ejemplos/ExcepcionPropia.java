/*
 * Lanzar excepciones (throw) y crear una propia.
 */
class SaldoInsuficienteException extends RuntimeException {
    public SaldoInsuficienteException(String mensaje) {
        super(mensaje);
    }
}

public class ExcepcionPropia {
    static void retirar(double saldo, double monto) {
        if (monto < 0) throw new IllegalArgumentException("monto negativo");
        if (monto > saldo) throw new SaldoInsuficienteException("saldo insuficiente");
        System.out.println("Retiro exitoso de " + monto);
    }

    public static void main(String[] args) {
        double saldo = 100;
        double[] intentos = {50, 200, -10};
        for (double m : intentos) {
            try {
                retirar(saldo, m);
            } catch (SaldoInsuficienteException e) {
                System.out.println("Rechazado: " + e.getMessage());
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}
