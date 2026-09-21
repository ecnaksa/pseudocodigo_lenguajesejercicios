/*
 * Excepcion propia (hereda de std::exception) y varios catch.
 */
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class SaldoInsuficiente : public exception {
public:
    const char* what() const noexcept override {
        return "saldo insuficiente";
    }
};

void retirar(double saldo, double monto) {
    if (monto < 0) throw invalid_argument("monto negativo");
    if (monto > saldo) throw SaldoInsuficiente();
    cout << "Retiro exitoso de " << monto << endl;
}

int main() {
    double saldo = 100;
    for (double m : {50.0, 200.0, -10.0}) {
        try {
            retirar(saldo, m);
        } catch (const SaldoInsuficiente &e) {
            cout << "Rechazado: " << e.what() << endl;
        } catch (const exception &e) {           // atrapa el resto
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
