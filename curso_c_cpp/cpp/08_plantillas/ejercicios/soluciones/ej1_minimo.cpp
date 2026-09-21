/* Ejercicio 1 - minimo generico. */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T minimo(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << minimo(3, 7) << endl;                          // 3
    cout << minimo(2.5, 1.8) << endl;                      // 1.8
    cout << minimo(string("pera"), string("uva")) << endl; // pera
    return 0;
}
