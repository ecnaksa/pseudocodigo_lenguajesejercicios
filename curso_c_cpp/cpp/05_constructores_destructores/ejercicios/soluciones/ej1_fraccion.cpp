/* Ejercicio 1 - Fraccion con constructor y valor por defecto. */
#include <iostream>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;
public:
    Fraccion(int num, int den = 1) : numerador(num), denominador(den) {}

    double valor() {
        if (denominador == 0) return 0;
        return (double) numerador / denominador;
    }
};

int main() {
    Fraccion media(1, 2);
    Fraccion entero(5);          // denominador = 1
    cout << "1/2 = " << media.valor() << endl;    // 0.5
    cout << "5/1 = " << entero.valor() << endl;   // 5
    return 0;
}
