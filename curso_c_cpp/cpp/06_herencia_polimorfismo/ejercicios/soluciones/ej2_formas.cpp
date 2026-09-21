/* Ejercicio 2 - Clase abstracta Forma y derivadas. */
#include <iostream>
using namespace std;

class Forma {
public:
    virtual double area() = 0;
    virtual ~Forma() {}
};

class Cuadrado : public Forma {
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double area() override { return lado * lado; }
};

class Triangulo : public Forma {
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double area() override { return base * altura / 2.0; }
};

int main() {
    Forma *formas[2];
    formas[0] = new Cuadrado(4);
    formas[1] = new Triangulo(3, 6);
    for (int i = 0; i < 2; i++) {
        cout << "Area: " << formas[i]->area() << endl;   // 16, 9
    }
    for (int i = 0; i < 2; i++) delete formas[i];
    return 0;
}
