/*
 * unique_ptr: propiedad exclusiva, se libera solo (RAII). Sin delete a mano.
 */
#include <iostream>
#include <memory>
using namespace std;

class Recurso {
public:
    Recurso()  { cout << "Recurso adquirido\n"; }
    ~Recurso() { cout << "Recurso liberado\n"; }
    void usar() { cout << "Usando el recurso\n"; }
};

int main() {
    cout << "-- entrando al bloque --\n";
    {
        unique_ptr<Recurso> r = make_unique<Recurso>();
        r->usar();
    }   // aqui r se destruye: el Recurso se libera automaticamente
    cout << "-- fuera del bloque --\n";

    unique_ptr<int> n = make_unique<int>(42);
    cout << "Valor: " << *n << endl;
    return 0;                     // n se libera solo al terminar
}
