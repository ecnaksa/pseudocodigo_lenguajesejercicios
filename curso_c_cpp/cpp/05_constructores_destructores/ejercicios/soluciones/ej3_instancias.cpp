/* Ejercicio 3 - Contador de instancias vivas con static. */
#include <iostream>
using namespace std;

class Objeto {
public:
    static int vivos;
    Objeto()  { vivos++; }
    ~Objeto() { vivos--; }
};

int Objeto::vivos = 0;

int main() {
    Objeto a;
    cout << "Vivos: " << Objeto::vivos << endl;   // 1
    {
        Objeto b, c;
        cout << "Vivos: " << Objeto::vivos << endl;  // 3
    }                                                // b y c se destruyen
    cout << "Vivos: " << Objeto::vivos << endl;   // 1
    return 0;
}
