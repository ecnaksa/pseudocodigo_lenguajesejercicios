/* Ejercicio 1 - Clase Circulo. */
#include <iostream>
using namespace std;

class Circulo {
public:
    double radio;

    double area() {
        return 3.14159265 * radio * radio;
    }
    double circunferencia() {
        return 2 * 3.14159265 * radio;
    }
};

int main() {
    Circulo c;
    c.radio = 5;
    cout << "Area: " << c.area() << endl;
    cout << "Circunferencia: " << c.circunferencia() << endl;
    return 0;
}
