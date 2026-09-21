/*
 * Parametros por defecto.
 */
#include <iostream>
#include <string>
using namespace std;

double potencia(double base, int exp = 2) {   // exp por defecto = 2
    double r = 1;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}

void saludar(const string &nombre, const string &saludo = "Hola") {
    cout << saludo << ", " << nombre << endl;
}

int main() {
    cout << potencia(5) << endl;       // 25  (exp = 2)
    cout << potencia(5, 3) << endl;    // 125

    saludar("Ana");                    // Hola, Ana
    saludar("Luis", "Buenos dias");    // Buenos dias, Luis
    return 0;
}
