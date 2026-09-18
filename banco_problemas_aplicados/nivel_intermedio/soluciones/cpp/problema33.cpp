/*
 * Problema 33 - Compresion de Datos por Submuestreo
 * Toma las muestras en indices 0, K, 2K, ... Devuelve el nuevo tamano.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int submuestrea(double arr[], int n, int k, double res[]) {
    int j = 0;
    for (int i = 0; i < n; i = i + k) {
        res[j] = arr[i];
        j = j + 1;
    }
    return j;
}

int main() {
    int n, k;
    cout << "Ingrese el numero de muestras: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Muestra " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese el factor de compresion K: ";
    cin >> k;

    double* res = new double[n];
    int nuevo = submuestrea(arr, n, k, res);

    cout << fixed << setprecision(2);
    cout << "Vector comprimido (" << nuevo << " muestras): ";
    for (int i = 0; i < nuevo; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] res;
    return 0;
}
