/* Ejercicio 4 (reto) - imprimir sobrecargado por tipo. */
#include <iostream>
#include <string>
using namespace std;

void imprimir(int v)    { cout << "int: " << v << endl; }
void imprimir(double v) { cout << "double: " << v << endl; }
void imprimir(const string &v) { cout << "string: " << v << endl; }

int main() {
    imprimir(42);
    imprimir(3.14);
    imprimir(string("hola"));
    return 0;
}
