/*
 * Plantilla de clase: una Pila (LIFO) generica.
 */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pila {
    T datos[100];
    int tope = 0;
public:
    void push(T valor) { datos[tope++] = valor; }
    T pop() { return datos[--tope]; }
    bool vacia() const { return tope == 0; }
};

int main() {
    Pila<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    while (!p.vacia()) {
        cout << p.pop() << " ";   // 3 2 1 (ultimo en entrar, primero en salir)
    }
    cout << endl;
    return 0;
}
