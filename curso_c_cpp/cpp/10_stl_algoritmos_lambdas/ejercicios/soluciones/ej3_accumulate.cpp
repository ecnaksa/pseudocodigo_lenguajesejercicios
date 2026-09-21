/* Ejercicio 3 - Suma y promedio con accumulate. */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<double> v = {8.5, 7.0, 9.2, 6.8, 10.0};

    double suma = accumulate(v.begin(), v.end(), 0.0);   // 0.0 -> resultado double
    double promedio = suma / v.size();

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    return 0;
}
