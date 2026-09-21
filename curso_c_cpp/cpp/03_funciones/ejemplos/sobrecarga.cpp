/*
 * Sobrecarga: mismo nombre, distintos parametros.
 */
#include <iostream>
#include <string>
using namespace std;

int    sumar(int a, int b)        { return a + b; }
double sumar(double a, double b)  { return a + b; }
int    sumar(int a, int b, int c) { return a + b + c; }
string sumar(string a, string b)  { return a + b; }   // "sumar" cadenas = concatenar

int main() {
    cout << sumar(3, 4) << endl;            // enteros -> 7
    cout << sumar(3.5, 4.2) << endl;        // doubles -> 7.7
    cout << sumar(1, 2, 3) << endl;         // tres int -> 6
    cout << sumar(string("Hola "), string("mundo")) << endl;
    return 0;
}
