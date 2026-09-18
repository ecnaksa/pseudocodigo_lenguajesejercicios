/*
 * Problema 05 - Consumo Exclusivo de Cargas Pares
 * double sumaPares(double Arr[], int tam)  -> acumula valores en INDICES pares (i % 2 == 0)
 */
#include <iostream>
#include <iomanip>
using namespace std;

double sumaPares(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            suma = suma + arr[i];
        }
    }
    return suma;
}

int main() {
    int tam;
    cout << "Ingrese el numero de lecturas: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Lectura " << i << ": ";
        cin >> arr[i];
    }

    cout << fixed << setprecision(2);
    cout << "Suma de las cargas en indices pares: " << sumaPares(arr, tam) << endl;

    delete[] arr;
    return 0;
}
