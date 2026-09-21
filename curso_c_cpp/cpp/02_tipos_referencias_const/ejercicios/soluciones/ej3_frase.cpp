/* Ejercicio 3 - Contar caracteres de una frase leida con getline. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Escribe una frase: ";
    string frase;
    getline(cin, frase);
    cout << "Tiene " << frase.length() << " caracteres." << endl;
    return 0;
}
