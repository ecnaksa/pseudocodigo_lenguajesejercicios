/*
 * Problema 39 - Analisis de Simetria Espectral Basica
 * bool esSimetrico(double Arr[], int n)  ->  Arr[i] == Arr[n-1-i] (palindromo).
 */
#include <iostream>
using namespace std;

bool esSimetrico(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Ingrese el tamano del vector: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arr[i];
    }

    if (esSimetrico(arr, n)) {
        cout << "El vector es simetrico (mitades opuestas coinciden)." << endl;
    } else {
        cout << "El vector NO es simetrico." << endl;
    }

    delete[] arr;
    return 0;
}
