/*
 * Miembro static: contar cuantos objetos se han creado.
 */
#include <iostream>
using namespace std;

class Usuario {
public:
    static int total;       // compartido por toda la clase
    Usuario() { total++; }
};

int Usuario::total = 0;     // definicion (una sola vez, fuera de la clase)

int main() {
    Usuario a, b, c;
    cout << "Usuarios creados: " << Usuario::total << endl;   // 3
    return 0;
}
