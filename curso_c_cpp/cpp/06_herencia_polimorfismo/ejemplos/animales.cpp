/*
 * Herencia + polimorfismo con funciones virtuales.
 */
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;
public:
    Animal(const string &n) : nombre(n) {}
    virtual void hacerSonido() {              // virtual: polimorfico
        cout << nombre << ": sonido generico\n";
    }
    virtual ~Animal() {}                      // destructor virtual
};

class Perro : public Animal {
public:
    Perro(const string &n) : Animal(n) {}
    void hacerSonido() override { cout << nombre << ": Guau\n"; }
};

class Gato : public Animal {
public:
    Gato(const string &n) : Animal(n) {}
    void hacerSonido() override { cout << nombre << ": Miau\n"; }
};

int main() {
    Animal *animales[3];
    animales[0] = new Perro("Rex");
    animales[1] = new Gato("Michi");
    animales[2] = new Animal("Bestia");

    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();          // cada uno responde segun su tipo real
    }
    for (int i = 0; i < 3; i++) delete animales[i];   // liberar
    return 0;
}
