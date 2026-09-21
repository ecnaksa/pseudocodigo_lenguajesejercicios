/* Ejercicio 4 (reto) - Mayor de dos con bool y ternario. */
#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Dos numeros: ";
    cin >> a >> b;

    bool aEsMayor = (a > b);
    cout << "El mayor es " << (aEsMayor ? a : b) << endl;
    return 0;
}
