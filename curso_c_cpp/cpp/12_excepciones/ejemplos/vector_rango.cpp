/*
 * vector::at lanza out_of_range si te sales de los limites.
 */
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    try {
        cout << v.at(1) << endl;    // 20 (ok)
        cout << v.at(10) << endl;   // fuera de rango -> lanza
    } catch (const out_of_range &e) {
        cout << "Indice invalido: " << e.what() << endl;
    }
    return 0;
}
