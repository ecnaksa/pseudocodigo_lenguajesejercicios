/* Ejercicio 1 - Nombre completo con string. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre, apellido;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;

    string completo = nombre + " " + apellido;
    cout << completo << " (" << completo.length() << " caracteres)" << endl;
    return 0;
}
