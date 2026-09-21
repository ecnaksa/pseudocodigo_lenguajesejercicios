/*
 * Lambdas con algoritmos: sort con criterio, count_if, for_each, transform, capturas.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 4};

    // Ordenar de mayor a menor con una lambda
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    cout << "Descendente: ";
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    // Contar los pares
    int pares = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "Pares: " << pares << endl;

    // Contar los mayores que un umbral (captura)
    int umbral = 4;
    int grandes = count_if(v.begin(), v.end(), [umbral](int x) { return x > umbral; });
    cout << "Mayores que " << umbral << ": " << grandes << endl;

    // Duplicar cada elemento
    transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
    cout << "Duplicados: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
