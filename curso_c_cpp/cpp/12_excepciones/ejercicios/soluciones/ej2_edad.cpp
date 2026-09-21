/* Ejercicio 2 - Validar edad con excepcion. */
#include <iostream>
#include <stdexcept>
using namespace std;

void validarEdad(int e) {
    if (e < 0)   throw invalid_argument("edad negativa");
    if (e > 150) throw invalid_argument("edad demasiado grande");
    cout << "Edad valida: " << e << endl;
}

int main() {
    for (int e : {25, -3, 200}) {
        try {
            validarEdad(e);
        } catch (const exception &ex) {
            cout << "Error con " << e << ": " << ex.what() << endl;
        }
    }
    return 0;
}
