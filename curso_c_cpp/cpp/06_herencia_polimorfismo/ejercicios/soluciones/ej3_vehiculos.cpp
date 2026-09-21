/* Ejercicio 3 (reto) - Vehiculos polimorficos. */
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
public:
    Vehiculo(const string &m) : marca(m) {}
    virtual void describir() { cout << "Vehiculo " << marca << endl; }
    virtual ~Vehiculo() {}
};

class Coche : public Vehiculo {
public:
    Coche(const string &m) : Vehiculo(m) {}
    void describir() override { cout << "Coche " << marca << " (4 ruedas)" << endl; }
};

class Moto : public Vehiculo {
public:
    Moto(const string &m) : Vehiculo(m) {}
    void describir() override { cout << "Moto " << marca << " (2 ruedas)" << endl; }
};

int main() {
    Vehiculo *v[3];
    v[0] = new Coche("Toyota");
    v[1] = new Moto("Honda");
    v[2] = new Vehiculo("Generico");
    for (int i = 0; i < 3; i++) v[i]->describir();
    for (int i = 0; i < 3; i++) delete v[i];
    return 0;
}
