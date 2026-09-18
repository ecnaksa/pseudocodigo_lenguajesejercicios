/*
 * Problema 23 - Inversion Espectral In-Place en Memoria
 * void invertirBuffer(int Arr[], int tam)  -> invierte in-place, solo una variable temporal.
 */
#include <iostream>
using namespace std;

void invertirBuffer(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];
        arr[i] = arr[tam - 1 - i];
        arr[tam - 1 - i] = aux;
    }
}

int main() {
    int tam;
    cout << "Ingrese el tamano del buffer: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Dato " << i << ": ";
        cin >> arr[i];
    }

    invertirBuffer(arr, tam);

    cout << "Buffer invertido: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
