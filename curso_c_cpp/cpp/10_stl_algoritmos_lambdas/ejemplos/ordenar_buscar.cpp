/*
 * Algoritmos de <algorithm> y <numeric>: sort, find, count, max_element, accumulate.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 2};

    sort(v.begin(), v.end());
    cout << "Ordenado: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    auto it = find(v.begin(), v.end(), 8);
    if (it != v.end()) cout << "8 esta en la posicion " << (it - v.begin()) << endl;

    cout << "Cuantos 2: " << count(v.begin(), v.end(), 2) << endl;
    cout << "Maximo: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Suma: " << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
}
