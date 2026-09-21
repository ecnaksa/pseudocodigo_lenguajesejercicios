/* Ejercicio 1 - Promedio de un vector<double>. */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> notas = {8.5, 7.0, 9.2, 6.8, 10.0};

    double suma = 0;
    for (double n : notas) suma += n;
    double promedio = suma / notas.size();

    cout << "Promedio: " << promedio << endl;
    return 0;
}
