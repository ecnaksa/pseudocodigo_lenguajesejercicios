/*
 * Problema 38 - Inversion Condicional de Negativos
 * Rectifica: aplica valor absoluto solo donde Arr[i] < 0.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void rectifica(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de mediciones: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Medicion " << i << ": ";
        cin >> arr[i];
    }

    rectifica(arr, n);

    cout << fixed << setprecision(2);
    cout << "Senal rectificada: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
