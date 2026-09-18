/*
 * Ejercicio 12 - Nivel Avanzado
 * void invierteArreglo(int Arr[], int tam)
 * Modifica el orden de los elementos de manera que queden invertidos.
 */
#include <iostream>
using namespace std;

void invierteArreglo(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];
        arr[i] = arr[tam - 1 - i];
        arr[tam - 1 - i] = aux;
    }
}

int main() {
    int tam;
    cout << "Ingrese el tamano del arreglo: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }

    invierteArreglo(arr, tam);

    cout << "El nuevo arreglo (invertido) es:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
