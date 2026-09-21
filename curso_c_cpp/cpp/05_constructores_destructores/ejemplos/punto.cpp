/*
 * Constructores: por defecto, con parametros y lista de inicializacion.
 */
#include <iostream>
using namespace std;

class Punto {
public:
    double x, y;

    Punto() : x(0), y(0) {}                     // por defecto
    Punto(double px, double py) : x(px), y(py) {}  // con parametros

    void mostrar() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Punto a;            // (0, 0)
    Punto b(3, 4);      // (3, 4)
    a.mostrar();
    b.mostrar();
    return 0;
}
