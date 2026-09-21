/* Ejercicio 4 (reto) - Clase Libro con lista de inicializacion. */
#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro(const string &t, const string &a, int p)
        : titulo(t), autor(a), paginas(p) {}

    void describir() {
        cout << "\"" << titulo << "\" de " << autor
             << " (" << paginas << " paginas)" << endl;
    }
};

int main() {
    Libro l("El Quijote", "Cervantes", 863);
    l.describir();
    return 0;
}
