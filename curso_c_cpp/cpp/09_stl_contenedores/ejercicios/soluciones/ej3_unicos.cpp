/* Ejercicio 3 - Valores unicos con set. */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> datos = {5, 2, 8, 2, 5, 1, 8, 8};

    set<int> unicos(datos.begin(), datos.end());

    cout << "Unicos: ";
    for (int x : unicos) cout << x << " ";   // 1 2 5 8
    cout << endl;
    return 0;
}
