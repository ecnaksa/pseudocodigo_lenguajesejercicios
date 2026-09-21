/*
 * throw / try / catch basico: division segura.
 */
#include <iostream>
#include <stdexcept>
using namespace std;

double dividir(double a, double b) {
    if (b == 0) {
        throw runtime_error("division entre cero");
    }
    return a / b;
}

int main() {
    try {
        cout << "10 / 2 = " << dividir(10, 2) << endl;   // 5
        cout << "10 / 0 = " << dividir(10, 0) << endl;   // lanza
        cout << "no se imprime\n";
    } catch (const runtime_error &e) {
        cout << "Error atrapado: " << e.what() << endl;
    }
    cout << "El programa continua normalmente\n";
    return 0;
}
