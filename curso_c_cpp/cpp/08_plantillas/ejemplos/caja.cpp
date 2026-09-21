/*
 * Plantilla de clase: una Caja que guarda un valor de cualquier tipo.
 */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Caja {
    T contenido;
public:
    Caja(T valor) : contenido(valor) {}
    T obtener() const { return contenido; }
    void poner(T valor) { contenido = valor; }
};

int main() {
    Caja<int> ci(42);
    Caja<string> cs("hola");

    cout << ci.obtener() << endl;    // 42
    cout << cs.obtener() << endl;    // hola

    ci.poner(100);
    cout << ci.obtener() << endl;    // 100
    return 0;
}
