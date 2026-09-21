/* Ejercicio 1 - Raiz cuadrada segura con excepcion. */
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double raizSegura(double x) {
    if (x < 0) throw invalid_argument("no existe raiz real de un negativo");
    return sqrt(x);
}

int main() {
    for (double v : {16.0, -4.0, 2.0}) {
        try {
            cout << "raiz(" << v << ") = " << raizSegura(v) << endl;
        } catch (const invalid_argument &e) {
            cout << "Error con " << v << ": " << e.what() << endl;
        }
    }
    return 0;
}
