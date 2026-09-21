/* Ejercicio 1 - unique_ptr a un objeto. */
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Perro {
    string nombre;
public:
    Perro(const string &n) : nombre(n) {}
    void ladrar() { cout << nombre << " dice guau\n"; }
};

int main() {
    unique_ptr<Perro> p = make_unique<Perro>("Rex");
    p->ladrar();
    return 0;                 // Rex se libera solo
}
