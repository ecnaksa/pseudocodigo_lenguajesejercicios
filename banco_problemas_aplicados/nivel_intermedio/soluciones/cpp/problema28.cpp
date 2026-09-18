/*
 * Problema 28 - Normalizacion Lineal de Rango [0.0, 1.0]
 * Divide cada valor entre el maximo absoluto hallado.
 */
#include <iostream>
#include <iomanip>
#include <cmath>          // std::fabs
using namespace std;

void normaliza(double arr[], int n) {
    double maxVal = fabs(arr[0]);
    for (int i = 1; i < n; i++) {
        if (fabs(arr[i]) > maxVal) {
            maxVal = fabs(arr[i]);
        }
    }
    if (maxVal == 0.0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / maxVal;
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de valores: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Valor " << i << ": ";
        cin >> arr[i];
    }

    normaliza(arr, n);

    cout << fixed << setprecision(3);
    cout << "Vector normalizado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
