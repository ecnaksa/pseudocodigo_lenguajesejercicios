/*
 * Problema 02 - Voltaje Minimo en Banco Solar
 * double buscaMinimo(double Arr[], int tam)
 */
#include <iostream>
#include <iomanip>
using namespace std;

double buscaMinimo(double arr[], int tam) {
    double min = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int tam;
    cout << "Ingrese el numero de celdas: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Voltaje de la celda " << i << " (V): ";
        cin >> arr[i];
    }

    cout << fixed << setprecision(2);
    cout << "Voltaje minimo detectado: " << buscaMinimo(arr, tam) << " V" << endl;

    delete[] arr;
    return 0;
}
