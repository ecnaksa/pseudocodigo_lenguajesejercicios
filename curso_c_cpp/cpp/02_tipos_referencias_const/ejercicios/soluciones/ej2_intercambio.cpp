/* Ejercicio 2 - Intercambio por referencia (mucho mas limpio que con punteros). */
#include <iostream>
using namespace std;

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    cout << "Antes:   x=" << x << ", y=" << y << endl;
    intercambiar(x, y);            // sin & en la llamada
    cout << "Despues: x=" << x << ", y=" << y << endl;
    return 0;
}
