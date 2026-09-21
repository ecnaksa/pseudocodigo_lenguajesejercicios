/*
 * std::vector: arreglo dinamico. Agregar, recorrer, tamano.
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i * i);          // 1, 4, 9, 16, 25
    }

    cout << "Tamano: " << v.size() << endl;
    cout << "Elementos: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Primero: " << v.front() << ", ultimo: " << v.back() << endl;

    int suma = 0;
    for (int x : v) suma += x;
    cout << "Suma: " << suma << endl;   // 55
    return 0;
}
