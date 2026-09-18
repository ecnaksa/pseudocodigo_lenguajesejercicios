/*
 * Ejercicio 05 - Nivel Intermedio
 * int sumaPares(int Arr[], int tam)
 * Regresa la suma de solo los numeros pares del arreglo.
 */
#include <iostream>
using namespace std;

int sumaPares(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 == 0) {
            suma = suma + arr[i];
        }
    }
    return suma;
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

    cout << "La suma de los numeros pares es: " << sumaPares(arr, tam) << endl;

    delete[] arr;
    return 0;
}
