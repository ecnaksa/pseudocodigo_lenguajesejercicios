/* Ejercicio 2 - CuentaBancaria con constructor. */
#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    double saldo;
public:
    CuentaBancaria(double inicial = 0) : saldo(inicial) {}

    void depositar(double m) { if (m > 0) saldo += m; }
    void retirar(double m)   { if (m > 0 && m <= saldo) saldo -= m; }
    double consultar()       { return saldo; }
};

int main() {
    CuentaBancaria c(100);       // nace con 100
    c.depositar(50);
    c.retirar(30);
    cout << "Saldo: " << c.consultar() << endl;   // 120
    return 0;
}
