/*
 * Primera clase: Rectangulo, con atributos publicos y un metodo.
 */
#include <iostream>
using namespace std;

class Rectangulo {
public:
    double base;
    double altura;

    double area() {
        return base * altura;
    }
    double perimetro() {
        return 2 * (base + altura);
    }
};

int main() {
    Rectangulo r;              // objeto
    r.base = 4;
    r.altura = 3;
    cout << "Area: " << r.area() << endl;            // 12
    cout << "Perimetro: " << r.perimetro() << endl;  // 14
    return 0;
}
