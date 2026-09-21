/* Ejercicio 1 - Empleado y Gerente (redefinir salario). */
#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    double basico;
public:
    Empleado(const string &n, double b) : nombre(n), basico(b) {}
    virtual double salario() { return basico; }
    virtual ~Empleado() {}
    string getNombre() { return nombre; }
};

class Gerente : public Empleado {
    double bono;
public:
    Gerente(const string &n, double b, double bo) : Empleado(n, b), bono(bo) {}
    double salario() override { return basico + bono; }
};

int main() {
    Empleado e("Ana", 1000);
    Gerente g("Luis", 1000, 500);
    cout << e.getNombre() << ": " << e.salario() << endl;   // 1000
    cout << g.getNombre() << ": " << g.salario() << endl;   // 1500
    return 0;
}
