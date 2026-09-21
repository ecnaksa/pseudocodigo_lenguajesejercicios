/*
 * Plantilla de funcion: un solo maximo para todos los tipos comparables.
 */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maximo(3, 7) << endl;                       // int
    cout << maximo(2.5, 1.8) << endl;                   // double
    cout << maximo(string("manzana"), string("pera")) << endl;  // string
    cout << maximo('a', 'z') << endl;                   // char
    return 0;
}
