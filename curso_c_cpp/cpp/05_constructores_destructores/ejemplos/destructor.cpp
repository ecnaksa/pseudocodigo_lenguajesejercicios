/*
 * Constructor y destructor: observa cuando se ejecuta cada uno.
 */
#include <iostream>
#include <string>
using namespace std;

class Recurso {
private:
    string nombre;
public:
    Recurso(const string &n) : nombre(n) {
        cout << "Creado: " << nombre << endl;
    }
    ~Recurso() {
        cout << "Liberado: " << nombre << endl;
    }
};

int main() {
    Recurso a("A");
    {
        Recurso b("B");     // b vive solo dentro de este bloque
        cout << "-- dentro del bloque --" << endl;
    }                       // aqui se destruye b
    cout << "-- fin de main --" << endl;
    return 0;
}                           // aqui se destruye a
