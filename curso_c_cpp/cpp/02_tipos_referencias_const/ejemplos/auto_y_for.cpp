/*
 * auto (deduccion de tipo) y el for "para cada".
 */
#include <iostream>
using namespace std;

int main() {
    auto x = 5;            // int
    auto pi = 3.14;        // double
    cout << "x=" << x << ", pi=" << pi << endl;

    int numeros[] = {10, 20, 30, 40};
    int suma = 0;
    for (int n : numeros) {          // recorre cada elemento
        suma += n;
    }
    cout << "Suma: " << suma << endl;

    cout << "Elementos: ";
    for (const auto &n : numeros) {  // con auto y referencia const
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
