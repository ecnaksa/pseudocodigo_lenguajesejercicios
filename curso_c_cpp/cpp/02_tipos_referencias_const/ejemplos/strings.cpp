/*
 * std::string: concatenar, comparar, longitud, substr, find, getline.
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre = "Ana";
    string apellido = "Perez";
    string completo = nombre + " " + apellido;    // concatenar con +

    cout << completo << " (" << completo.length() << " caracteres)" << endl;

    if (nombre == "Ana") cout << "El nombre es Ana" << endl;   // comparar con ==

    cout << "Primeros 3: " << completo.substr(0, 3) << endl;   // "Ana"
    cout << "Posicion de 'Perez': " << completo.find("Perez") << endl;  // 4

    cout << "Escribe una frase: ";
    string frase;
    getline(cin, frase);                          // linea completa (con espacios)
    cout << "Dijiste: " << frase << endl;
    return 0;
}
