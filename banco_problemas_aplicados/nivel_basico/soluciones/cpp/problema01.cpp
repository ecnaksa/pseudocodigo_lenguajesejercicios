/*
 * Problema 01 - Suma de Muestras de Corriente ADC
 * double sumaCorrientes(double Arr[], int tam)  -> sumatoria total (amperios)
 */
#include <iostream>
#include <iomanip>
using namespace std;

double sumaCorrientes(double arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }
    return suma;
}

int main() {
    int tam;
    cout << "Ingrese el numero de muestras: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Muestra " << i << " (A): ";
        cin >> arr[i];
    }

    cout << fixed << setprecision(2);
    cout << "Suma total de corrientes: " << sumaCorrientes(arr, tam) << " A" << endl;

    delete[] arr;
    return 0;
}
