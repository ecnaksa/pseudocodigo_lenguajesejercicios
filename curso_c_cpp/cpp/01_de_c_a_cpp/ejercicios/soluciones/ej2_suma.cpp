/* Ejercicio 2 - Suma con cin/cout. */
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Dos enteros: ";
    cin >> a >> b;                 // se pueden encadenar dos lecturas
    cout << "Suma: " << a + b << endl;
    return 0;
}
