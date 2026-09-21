/* Ejercicio 2 - Clase Contador con estado privado. */
#include <iostream>
using namespace std;

class Contador {
private:
    int valor = 0;          // inicializacion de miembro (C++11)

public:
    void incrementar() { valor++; }
    void reiniciar()   { valor = 0; }
    int  obtener()     { return valor; }
};

int main() {
    Contador c;
    c.incrementar();
    c.incrementar();
    c.incrementar();
    cout << "Valor: " << c.obtener() << endl;   // 3
    c.reiniciar();
    cout << "Tras reiniciar: " << c.obtener() << endl;  // 0
    return 0;
}
