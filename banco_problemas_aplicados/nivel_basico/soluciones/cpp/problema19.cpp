/*
 * Problema 19 - Inversion Espejo de Primera Mitad
 * void espejoPrimeraMitad(double Arr[], int n)  ->  Arr[n-1-i] = Arr[i]  (queda simetrico)
 */
#include <iostream>
#include <iomanip>
using namespace std;

void espejoPrimeraMitad(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        arr[n - 1 - i] = arr[i];
    }
}

int main() {
    int n;
    cout << "Ingrese el tamano del vector: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Dato " << i << ": ";
        cin >> arr[i];
    }

    espejoPrimeraMitad(arr, n);

    cout << fixed << setprecision(2);
    cout << "Vector simetrizado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
