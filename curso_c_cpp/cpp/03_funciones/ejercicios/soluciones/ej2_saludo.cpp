/* Ejercicio 2 - Saludo con parametro por defecto. */
#include <iostream>
#include <string>
using namespace std;

void saludar(const string &nombre, int veces = 1) {
    for (int i = 0; i < veces; i++) {
        cout << "Hola, " << nombre << "!" << endl;
    }
}

int main() {
    saludar("Ana");           // una vez
    saludar("Luis", 3);       // tres veces
    return 0;
}
