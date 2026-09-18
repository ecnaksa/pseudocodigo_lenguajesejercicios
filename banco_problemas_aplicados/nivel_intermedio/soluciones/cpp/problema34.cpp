/*
 * Problema 34 - Verificacion de Orden Estricto Creciente
 * bool esCreciente(double Arr[], int tam)  ->  Arr[i] < Arr[i+1] para todo i.
 */
#include <iostream>
using namespace std;

bool esCreciente(double arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (!(arr[i] < arr[i + 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    int tam;
    cout << "Ingrese el tamano del vector: ";
    cin >> tam;

    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Calibracion " << i << ": ";
        cin >> arr[i];
    }

    if (esCreciente(arr, tam)) {
        cout << "El vector esta estrictamente ordenado de forma ascendente." << endl;
    } else {
        cout << "El vector NO esta estrictamente ordenado." << endl;
    }

    delete[] arr;
    return 0;
}
