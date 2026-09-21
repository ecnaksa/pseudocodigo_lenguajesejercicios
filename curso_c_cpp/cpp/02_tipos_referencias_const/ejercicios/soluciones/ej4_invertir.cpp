/* Ejercicio 4 (reto) - Invertir una palabra. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Palabra: ";
    cin >> s;

    string invertida = "";
    for (int i = (int) s.length() - 1; i >= 0; i--) {
        invertida += s[i];
    }
    cout << "Al reves: " << invertida << endl;
    return 0;
}
