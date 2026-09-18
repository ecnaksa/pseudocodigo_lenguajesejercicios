/*
 * Problema 14 - Ordenamiento Lineal Simple por Intercambio (burbuja)
 * 8 valores de calibracion, orden ascendente.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void ordenaIntercambio(double arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int f = 0; f < tam - 1 - i; f++) {
            if (arr[f] > arr[f + 1]) {
                double aux = arr[f];
                arr[f] = arr[f + 1];
                arr[f + 1] = aux;
            }
        }
    }
}

int main() {
    int tam = 8;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Valor de calibracion " << i << ": ";
        cin >> arr[i];
    }

    ordenaIntercambio(arr, tam);

    cout << fixed << setprecision(2);
    cout << "Valores ordenados: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
