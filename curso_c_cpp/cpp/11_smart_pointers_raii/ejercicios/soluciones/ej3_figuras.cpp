/* Ejercicio 3 (reto) - vector de unique_ptr<Figura> (polimorfismo sin fugas). */
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Figura {
public:
    virtual double area() = 0;
    virtual ~Figura() {}
};
class Circulo : public Figura {
    double r;
public:
    Circulo(double radio) : r(radio) {}
    double area() override { return 3.14159265 * r * r; }
};
class Rectangulo : public Figura {
    double b, h;
public:
    Rectangulo(double base, double altura) : b(base), h(altura) {}
    double area() override { return b * h; }
};

int main() {
    vector<unique_ptr<Figura>> figuras;
    figuras.push_back(make_unique<Circulo>(2));
    figuras.push_back(make_unique<Rectangulo>(3, 4));

    for (const auto &f : figuras) {
        cout << "Area: " << f->area() << endl;   // 12.566, 12
    }
    return 0;      // cada figura se libera sola al destruir el vector
}
