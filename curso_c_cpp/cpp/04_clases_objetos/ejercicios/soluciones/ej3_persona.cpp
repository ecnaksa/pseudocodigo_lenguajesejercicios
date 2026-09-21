/* Ejercicio 3 - Persona con getters/setters y validacion. */
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad = 0;

public:
    void setNombre(const string &n) { nombre = n; }
    string getNombre() { return nombre; }

    void setEdad(int e) {
        if (e >= 0) edad = e;              // no acepta negativos
        else cout << "Edad invalida\n";
    }
    int getEdad() { return edad; }
};

int main() {
    Persona p;
    p.setNombre("Ana");
    p.setEdad(25);
    p.setEdad(-3);                          // rechazado
    cout << p.getNombre() << ", " << p.getEdad() << " anios" << endl;
    return 0;
}
