/*
 * Clase abstracta (virtual pura) como interfaz: toda Figura tiene area().
 */
#include <iostream>
using namespace std;

class Figura {
public:
    virtual double area() = 0;       // virtual pura -> Figura es abstracta
    virtual ~Figura() {}
};

class Circulo : public Figura {
    double r;
public:
    Circulo(double radio) : r(radio) {}
    double area() override { return 3.14159265 * r * r; }
};

class Rectangulo : public Figura {
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double area() override { return base * altura; }
};

int main() {
    Figura *figuras[2];
    figuras[0] = new Circulo(2);
    figuras[1] = new Rectangulo(3, 4);

    for (int i = 0; i < 2; i++) {
        cout << "Area: " << figuras[i]->area() << endl;   // 12.566, 12
    }
    for (int i = 0; i < 2; i++) delete figuras[i];
    return 0;
}
