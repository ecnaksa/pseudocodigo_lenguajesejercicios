/*
 * Encapsulamiento: saldo privado, metodos publicos que lo protegen.
 */
#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    double saldo;

public:
    void inicializar() { saldo = 0; }

    void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }
    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Retiro invalido\n";
        }
    }
    double consultar() {
        return saldo;
    }
};

int main() {
    CuentaBancaria c;
    c.inicializar();
    c.depositar(100);
    c.retirar(30);
    c.retirar(1000);           // rechazado: no hay suficiente
    // c.saldo = 99999;        // ERROR si se descomenta: saldo es private
    cout << "Saldo: " << c.consultar() << endl;   // 70
    return 0;
}
