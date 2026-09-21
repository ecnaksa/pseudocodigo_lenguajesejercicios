/*
 * std::set: elementos unicos y ordenados. Ideal para quitar duplicados.
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> datos = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    set<int> unicos(datos.begin(), datos.end());   // construye set desde el vector

    cout << "Originales: " << datos.size() << " elementos\n";
    cout << "Unicos (" << unicos.size() << ", ordenados): ";
    for (int x : unicos) cout << x << " ";          // 1 2 3 4 5 6 9
    cout << endl;

    cout << "Contiene el 4? " << (unicos.count(4) ? "si" : "no") << endl;
    return 0;
}
