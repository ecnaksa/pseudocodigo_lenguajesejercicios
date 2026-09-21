/* Ejercicio 3 (reto) - Pila que lanza excepcion al hacer pop() vacia. */
#include <iostream>
#include <stdexcept>
using namespace std;

class Pila {
    int datos[100];
    int tope = 0;
public:
    void push(int v) { datos[tope++] = v; }
    int pop() {
        if (tope == 0) throw runtime_error("pila vacia");
        return datos[--tope];
    }
};

int main() {
    Pila p;
    p.push(10);
    cout << p.pop() << endl;    // 10

    try {
        p.pop();                // ya esta vacia -> lanza
    } catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
