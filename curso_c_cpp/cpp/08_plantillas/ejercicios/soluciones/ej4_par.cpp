/* Ejercicio 4 (reto) - Par generico con dos tipos distintos. */
#include <iostream>
#include <string>
using namespace std;

template <typename A, typename B>
class Par {
    A primero;
    B segundo;
public:
    Par(A a, B b) : primero(a), segundo(b) {}
    void mostrar() {
        cout << "(" << primero << ", " << segundo << ")" << endl;
    }
};

int main() {
    Par<int, string> p(1, "uno");
    Par<string, double> q("pi", 3.14);
    p.mostrar();     // (1, uno)
    q.mostrar();     // (pi, 3.14)
    return 0;
}
