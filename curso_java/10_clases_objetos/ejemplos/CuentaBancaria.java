/*
 * Encapsulamiento: saldo privado protegido por metodos publicos.
 */
public class CuentaBancaria {
    private double saldo;      // solo la clase puede tocarlo

    public void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }
    public void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
        } else {
            System.out.println("Retiro invalido");
        }
    }
    public double getSaldo() {
        return saldo;
    }

    public static void main(String[] args) {
        CuentaBancaria c = new CuentaBancaria();
        c.depositar(100);
        c.retirar(30);
        c.retirar(1000);           // rechazado
        // c.saldo = 99999;        // ERROR si se descomenta: saldo es private
        System.out.println("Saldo: " + c.getSaldo());   // 70
    }
}
