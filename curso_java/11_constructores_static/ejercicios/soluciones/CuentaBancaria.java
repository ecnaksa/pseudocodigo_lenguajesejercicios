/* Ejercicio 2 - CuentaBancaria con constructor. */
public class CuentaBancaria {
    private double saldo;

    public CuentaBancaria(double inicial) {
        this.saldo = inicial;
    }

    public void depositar(double m) { if (m > 0) saldo += m; }
    public void retirar(double m)   { if (m > 0 && m <= saldo) saldo -= m; }
    public double getSaldo()        { return saldo; }

    public static void main(String[] args) {
        CuentaBancaria c = new CuentaBancaria(100);   // nace con 100
        c.depositar(50);
        c.retirar(30);
        System.out.println("Saldo: " + c.getSaldo());  // 120
    }
}
