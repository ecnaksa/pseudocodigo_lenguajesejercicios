/*
 * Ejercicio 02 - Nivel Basico
 * int buscaMinimo(int Arr[], int tam)
 * Recibe un arreglo de enteros y regresa el valor minimo almacenado.
 */
#include <iostream>
using namespace std;

int buscaMinimo(int arr[], int tam) {
    int min = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
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

    cout << "El valor minimo es: " << buscaMinimo(arr, tam) << endl;

    delete[] arr;
    return 0;
}
