/* Ejercicio 2 - Contar aprobados con count_if y lambda. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> notas = {45, 70, 88, 55, 60, 92, 30};

    int aprobados = count_if(notas.begin(), notas.end(), [](int n) {
        return n >= 60;
    });
    cout << "Aprobados: " << aprobados << " de " << notas.size() << endl;   // 4 de 7
    return 0;
}
