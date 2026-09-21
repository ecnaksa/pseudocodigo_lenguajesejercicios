/* Ejercicio 1 - Saludo con string. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre;
    cout << "Tu nombre: ";
    cin >> nombre;                 // lee una palabra
    cout << "Hola, " << nombre << "!" << endl;
    return 0;
}
