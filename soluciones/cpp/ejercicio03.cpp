/*
 * Ejercicio 03 - Nivel Basico
 * int cuentaImpares(int Arr[], int tam)
 * Regresa la cantidad total de numeros impares que contiene el arreglo.
 */
#include <iostream>
using namespace std;

int cuentaImpares(int arr[], int tam) {
    int nimpar = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 != 0) {
            nimpar = nimpar + 1;
        }
    }
    return nimpar;
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

    cout << "La cantidad de numeros impares es: " << cuentaImpares(arr, tam) << endl;

    delete[] arr;
    return 0;
}
