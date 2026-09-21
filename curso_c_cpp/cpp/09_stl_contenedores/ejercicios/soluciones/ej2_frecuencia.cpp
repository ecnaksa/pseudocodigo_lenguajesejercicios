/* Ejercicio 2 - Frecuencia de letras con map<char,int>. */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string palabra;
    cout << "Palabra: ";
    cin >> palabra;

    map<char, int> frec;
    for (char c : palabra) {
        frec[c]++;               // si no existe, empieza en 0 y suma 1
    }

    for (const auto &par : frec) {
        cout << par.first << ": " << par.second << endl;
    }
    return 0;
}
