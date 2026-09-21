/*
 * Referencias: alias, paso por referencia y referencia const.
 */
#include <iostream>
#include <string>
using namespace std;

void duplicar(int &n) {                 // referencia: modifica el original
    n = n * 2;
}

void saludar(const string &nombre) {    // const& : no copia, no modifica
    cout << "Hola, " << nombre << endl;
}

int main() {
    int x = 5;
    duplicar(x);                        // sin & en la llamada
    cout << "x = " << x << endl;        // 10

    int &alias = x;                     // alias es otro nombre para x
    alias = 100;
    cout << "x = " << x << endl;        // 100

    string s = "Mundo";
    saludar(s);
    return 0;
}
